#include <iostream>
#include <string>
#include "folder.h"
#include "ConcreteObserver.h"

static void printNoteShort(const Note& n) {
    std::cout << "[" << n.id() << "] " << n.title();
    if (n.favorite()) std::cout << " ★";
    if (n.locked()) std::cout << " 🔒";
    std::cout << "\n";
}

int main() {
    Folder folder("MyNotes");
    ConcreteObserver observer;
    folder.addObserver(&observer);

    while (true) {
        std::cout << "\n=== NOTE MANAGER (" << folder.name() << ") ===\n"
                  << "1) add\n2) list\n3) view\n4) edit\n5) delete\n"
                  << "6) fav/unfav\n7) lock/unlock\n8) search\n9) list favorites\n0) exit\n> ";

        int c;
        if (!(std::cin >> c)) return 0;
        std::cin.ignore();

        if (c == 0) break;

        if (c == 1) {
            std::string t, x;
            std::cout << "Title: "; std::getline(std::cin, t);
            std::cout << "Text: ";  std::getline(std::cin, x);
            int id = folder.addNote(t, x);
            std::cout << "Added note id=" << id << "\n";
        }
        else if (c == 2) {
            for (const auto& n : folder.all()) printNoteShort(n);
        }
        else if (c == 3) {
            int id; std::cout << "Id: "; std::cin >> id; std::cin.ignore();
            auto n = folder.getCopy(id);
            if (!n) { std::cout << "Not found.\n"; continue; }
            std::cout << "\nTitle: " << n->title()
                      << "\nText: " << n->text()
                      << "\nFavorite: " << (n->favorite() ? "yes" : "no")
                      << "\nLocked: " << (n->locked() ? "yes" : "no") << "\n";
        }
        else if (c == 4) {
            int id; std::cout << "Id: "; std::cin >> id; std::cin.ignore();
            Note* n = folder.getMutable(id);
            if (!n) { std::cout << "Not found.\n"; continue; }
            std::string t, x;
            std::cout << "New title (empty = keep): "; std::getline(std::cin, t);
            std::cout << "New text  (empty = keep): "; std::getline(std::cin, x);

            bool ok = true;
            if (!t.empty()) ok = n->setTitle(t) && ok;
            if (!x.empty()) ok = n->setText(x) && ok;

            std::cout << (ok ? "Updated.\n" : "Blocked: note is locked.\n");
        }
        else if (c == 5) {
            int id; std::cout << "Id: "; std::cin >> id; std::cin.ignore();
            std::cout << (folder.removeNote(id) ? "Deleted.\n" : "Not found.\n");
        }
        else if (c == 6) {
            int id; std::cout << "Id: "; std::cin >> id; std::cin.ignore();
            Note* n = folder.getMutable(id);
            if (!n) { std::cout << "Not found.\n"; continue; }
            bool target = !n->favorite();
            std::cout << (n->setFavorite(target) ? "Done.\n" : "Blocked: note is locked.\n");
        }
        else if (c == 7) {
            int id; std::cout << "Id: "; std::cin >> id; std::cin.ignore();
            Note* n = folder.getMutable(id);
            if (!n) { std::cout << "Not found.\n"; continue; }
            if (n->locked()) { n->unlock(); std::cout << "Unlocked.\n"; }
            else { n->lock(); std::cout << "Locked.\n"; }
        }
        else if (c == 8) {
            std::string k; std::cout << "Keyword: "; std::getline(std::cin, k);
            auto res = folder.search(k);
            for (const auto& n : res) printNoteShort(n);
            if (res.empty()) std::cout << "No matches.\n";
        }
        else if (c == 9) {
            auto fav = folder.favorites();
            for (const auto& n : fav) printNoteShort(n);
            if (fav.empty()) std::cout << "No favorites.\n";
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
