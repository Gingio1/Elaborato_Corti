#ifndef NOTE_H
#define NOTE_H

#include <string>

class Note {
public:
    Note(int id, std::string title, std::string text);

    int id() const;
    const std::string& title() const;
    const std::string& text() const;

    bool locked() const;
    bool favorite() const;

    bool setTitle(const std::string& t);
    bool setText(const std::string& t);
    bool setFavorite(bool v);

    void lock();
    void unlock();

private:
    int id_;
    std::string title_;
    std::string text_;
    bool locked_ = false;
    bool favorite_ = false;
};

#endif
