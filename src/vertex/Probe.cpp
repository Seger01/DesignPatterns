#include <iostream>

#include "IOutputVisitor.h"
#include "Probe.h"

Probe Probe::m_cInstance("PROBE");

Probe::Probe() { std::cout << "Probe constructor" << std::endl; }

Probe::Probe(std::string id) : Vertex(id) {
    std::cout << "Probe assignment constructor" << std::endl;
    mValue = -1;
}

Probe::~Probe() { std::cout << "Probe destructor" << std::endl; }

void Probe::setInput(int aIndex, int aValue) {
    std::cout << "Probe::setInput" << std::endl;
    if (aIndex != 0) {
        std::cout << "Probe setInput error aIndex supposed to be 0 but is: " << aIndex << std::endl;
        return;
    }

    mValue = aValue;
    this->notify();
    return;
}
int Probe::getValue() { return mValue; }
int Probe::getOutput() {
    std::cout << "Probe::getOutput()" << std::endl;

    return mValue;
}

Vertex* Probe::clone() const { return new Probe; }

std::string Probe::whoAmI() { return std::string("I am a Probe!"); }

int Probe::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitProbe(this); }
