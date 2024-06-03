#include "XorGate.h"
#include <iostream>

XorGate XorGate::m_cInstance("XOR");

XorGate::XorGate() {
    std::cout << "XorGate default constructor" << std::endl;
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 2;
    mInput = new int[mMaxInputs];
}

XorGate::XorGate(std::string id) : Vertex(id) {
    std::cout << "XorGate assignment constructor" << std::endl;
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 2;
    mInput = new int[mMaxInputs];
}

XorGate::~XorGate() {
    std::cout << "XorGate destructor" << std::endl;
    if (mInput != nullptr) {
        delete mInput;
    }
}

void XorGate::setInput(int aIndex, int aValue) {
    if (aIndex < mAmountInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int XorGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mInput[0] == -1 || mInput[1] == -1) {
        std::cout << "Inputs not set yet!" << std::endl;
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

int XorGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor){
    return aIOutputVisitor.visitVertex(this);
}
