#include "OrGate.h"
#include <iostream>

OrGate OrGate::m_cInstance("OR");

OrGate::OrGate() {
    mInput = new int[mMaxInputs];
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
}

OrGate::OrGate(std::string id) : Vertex(id) {
    mInput = new int[mMaxInputs];
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
}

OrGate::~OrGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

int OrGate::getOutput() {
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
        if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to OR gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: "<< mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            // std::cout << "Input at index " << i << " not set yet!" << std::endl;
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

int OrGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
