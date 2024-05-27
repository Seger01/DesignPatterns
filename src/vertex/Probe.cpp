#include "Probe.h"
#include <iostream>

Probe Probe::m_cInstance(8);

Probe::Probe() {
    std::cout << "Probe default constructor" << std::endl;
    mValue = -1;
}

Probe::Probe(int id) : Vertex(id) {
    std::cout << "Probe assignment constructor" << std::endl;
    mValue = -1;
}

Probe::~Probe() {
    std::cout << "Probe destructor" << std::endl;
}

void Probe::setInput(unsigned aIndex, bool aValue) {
    mValue = aValue ? 1 : 0;
}

int Probe::getValue() {
    return mValue;
}

Vertex *Probe::clone() const {
    return new Probe;
}