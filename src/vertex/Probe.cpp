#include <iostream>

#include "IOutputVisitor.h"
#include "Probe.h"

Probe Probe::m_cInstance("PROBE");

Probe::Probe() {
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 0;

    // mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

Probe::Probe(std::string id) : Vertex(id) {
    mValue = -1;
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 0;

    // mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

Probe::~Probe() {}

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
int Probe::getOutput() { return mValue; }

Vertex* Probe::clone() const { return new Probe; }

std::string Probe::whoAmI() { return std::string("I am a Probe!"); }

int Probe::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitProbe(this); }
