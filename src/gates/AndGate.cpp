#include "AndGate.h"
#include <iostream>

AndGate AndGate::m_cInstance("AND");

AndGate::AndGate() {
    std::cout << "AndGate default constructor" << std::endl;
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

AndGate::AndGate(std::string id) : Vertex(id) {
    std::cout << "AndGate assignment constructor" << std::endl;
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

AndGate::~AndGate() {
    std::cout << "AndGate destructor" << std::endl;
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

void AndGate::setInput(unsigned aIndex, bool aValue) {
    if (aIndex < mAmountInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int AndGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 0) {
            return 0;
        }
    }
    return 1; // Not a single input was false, so return true
}

void AndGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs){
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for andgate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

Vertex *AndGate::clone() const {
    return new AndGate;
}