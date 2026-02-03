//
// Created by corti on 03/02/2026.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() const = 0;
};

#endif
