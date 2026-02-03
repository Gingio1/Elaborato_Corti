//
// Created by corti on 03/02/2026.
//
#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H

#include "Observer.h"
#include <iostream>

class ConcreteObserver : public Observer {
public:
    void update(const Folder& folder) override;
};

#endif
