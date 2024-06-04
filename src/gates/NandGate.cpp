#include "NandGate.h"
#include <iostream>

NandGate NandGate::m_cInstance("NAND");

NandGate::NandGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

NandGate::NandGate(std::string id) : Vertex(id) {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

NandGate::~NandGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

// void NandGate::setInput(int aIndex, int aValue) {
//     if (aIndex < mAmountInputs)
//         mInput[aIndex] = aValue ? 1 : 0;
// }
int NandGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
        if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to NAND gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: "<< mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            // std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 0) {
            return 1;
        }
    }
    return 0; // Not a single input was true, so return false
}

void NandGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for NandGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

Vertex* NandGate::clone() const { return new NandGate; }

std::string NandGate::whoAmI() { return std::string("I am a NandGate!"); }

int NandGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
