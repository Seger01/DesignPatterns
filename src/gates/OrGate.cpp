#include "OrGate.h"
#include <iostream>

OrGate OrGate::m_cInstance("OR");

OrGate::OrGate() {
    std::cout << "OrGate default constructor" << std::endl;
    mInput = new int[mMaxInputs];
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
}

OrGate::OrGate(std::string id) : Vertex(id) {
    std::cout << "OrGate assignment constructor" << std::endl;
    mInput = new int[mMaxInputs];
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
}

OrGate::~OrGate() {
    std::cout << "OrGate destructor" << std::endl;
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

void OrGate::setInput(int aIndex, int aValue) {
    if (aIndex < mAmountInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int OrGate::getOutput() {
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 1) {
            return 1;
        }
    }
    return 0; // Not a single input was true, so return false
}

void OrGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for OrGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

Vertex* OrGate::clone() const { return new OrGate; }

std::string OrGate::whoAmI() { return std::string("I am an OrGate!"); }
