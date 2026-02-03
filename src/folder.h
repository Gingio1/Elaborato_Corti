#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>
#include <optional>
#include <list>

#include "note.h"
#include "Subject.h"

class Folder : public Subject {
public:
    explicit Folder(std::string name);

    const std::string& name() const;

    int addNote(const std::string& title, const std::string& text);
    bool removeNote(int id);

    std::optional<Note> getCopy(int id) const;
    Note* getMutable(int id);

    const std::vector<Note>& all() const;

    std::vector<Note> search(const std::string& keyword) const;
    std::vector<Note> favorites() const;
    std::vector<Note> locked() const;

    // Observer pattern (implementazione in Folder.cpp)
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers() const override;

private:
    int nextId_ = 1;
    std::string name_;
    std::vector<Note> notes_;

    std::list<Observer*> observers_;
};

#endif
