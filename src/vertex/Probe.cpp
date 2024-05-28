#pragma once

#include <iostream>

#include "Probe.h"

Probe Probe::m_cInstance(8);

Probe::Probe() { std::cout << "Probe constructor" << std::endl; }

Probe::Probe(int id) : Vertex(id) {
    std::cout << "Probe assignment constructor" << std::endl;
    mValue = -1;
}

Probe::~Probe() { std::cout << "Probe destructor" << std::endl; }

void Probe::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Probe setInput error aIndex supposed to be 0 but is: " << aIndex << std::endl;
        return;
    }

    mValue = aValue;
    this->notify();
    return;
}
int Probe::getValue() { return mValue; }

Vertex* Probe::clone() const { return new Probe; }
