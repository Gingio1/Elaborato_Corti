//
// Created by corti on 03/02/2026.
//


#ifndef OBSERVER_H
#define OBSERVER_H

class Folder;  // forward declaration

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const Folder& folder) = 0;
};

#endif
