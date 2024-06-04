#include "XorGate.h"
#include <iostream>

XorGate XorGate::m_cInstance("XOR");

XorGate::XorGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 2;
    mInput = new int[mMaxInputs];
}

XorGate::XorGate(std::string id) : Vertex(id) {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 2;
    mInput = new int[mMaxInputs];
}

XorGate::~XorGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

int XorGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
        if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to XOR gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: "<< mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (mInput[0] == -1 || mInput[1] == -1) {
        // std::cout << "Inputs not set yet!" << std::endl;
        return -1;
    }
    if (mInput[0] == 1 && mInput[1] == 1) {
        return 0;
    }
    if (mInput[0] == 0 && mInput[1] == 0) {
        return 0;
    }
    return 1; // Not a single input was true, so return false
}

void XorGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for XorGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

Vertex* XorGate::clone() const { return new XorGate; }

std::string XorGate::whoAmI() { return std::string("I am an XorGate!"); }

int XorGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
