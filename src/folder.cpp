#include "folder.h"
#include <algorithm>



Folder::Folder(std::string name) : name_(std::move(name)) {}

const std::string& Folder::name() const {
    return name_;
}

int Folder::addNote(const std::string& title, const std::string& text) {
    int id = nextId_++;
    notes_.emplace_back(id, title, text);
    notifyObservers();
    return id;
}

bool Folder::removeNote(int id) {
    auto it = std::remove_if(notes_.begin(), notes_.end(),
                             [id](const Note& n) { return n.id() == id; });
    if (it == notes_.end()) return false;
    notes_.erase(it, notes_.end());
    notifyObservers();
    return true;
}

std::optional<Note> Folder::getCopy(int id) const {
    auto it = std::find_if(notes_.begin(), notes_.end(),
                           [id](const Note& n) { return n.id() == id; });
    if (it == notes_.end()) return std::nullopt;
    return *it;
}

Note* Folder::getMutable(int id) {
    auto it = std::find_if(notes_.begin(), notes_.end(),
                           [id](const Note& n) { return n.id() == id; });
    if (it == notes_.end()) return nullptr;
    return &(*it);
}

const std::vector<Note>& Folder::all() const {
    return notes_;
}

std::vector<Note> Folder::search(const std::string& keyword) const {
    std::vector<Note> out;
    for (const auto& n : notes_) {
        if (n.title().find(keyword) != std::string::npos ||
            n.text().find(keyword) != std::string::npos) {
            out.push_back(n);
            }
    }
    return out;
}

std::vector<Note> Folder::favorites() const {
    std::vector<Note> out;
    for (const auto& n : notes_) {
        if (n.favorite()) out.push_back(n);
    }
    return out;
}

std::vector<Note> Folder::locked() const {
    std::vector<Note> out;
    for (const auto& n : notes_) {
        if (n.locked()) out.push_back(n);
    }
    return out;
}
void Folder::addObserver(Observer* o) {
    observers_.push_back(o);
}

void Folder::removeObserver(Observer* o) {
    observers_.remove(o);
}

void Folder::notifyObservers() const {
    for (auto* o : observers_) {
        o->update(*this);
    }
}
