#include "ConcreteObserver.h"
#include "folder.h"

void ConcreteObserver::update(const Folder& folder) {
    std::cout << "[Observer] Numero di note: "
              << folder.all().size() << std::endl;
}
