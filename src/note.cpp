#include "note.h"
#include <utility>

Note::Note(int id, std::string title, std::string text)
        : id_(id), title_(std::move(title)), text_(std::move(text)) {}

int Note::id() const {
    return id_;
}

const std::string& Note::title() const {
    return title_;
}

const std::string& Note::text() const {
    return text_;
}

bool Note::locked() const {
    return locked_;
}

bool Note::favorite() const {
    return favorite_;
}

bool Note::setTitle(const std::string& t) {
    if (locked_) return false;
    title_ = t;
    return true;
}

bool Note::setText(const std::string& t) {
    if (locked_) return false;
    text_ = t;
    return true;
}

bool Note::setFavorite(bool v) {
    if (locked_) return false;
    favorite_ = v;
    return true;
}

void Note::lock() {
    locked_ = true;
}

void Note::unlock() {
    locked_ = false;
}
