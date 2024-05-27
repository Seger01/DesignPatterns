#include "NorGate.h"
#include <iostream>

NorGate::NorGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

NorGate::~NorGate() {
    if (mInput != nullptr) {
        delete mInput;
    }
}

void NorGate::setInput(unsigned aIndex, bool aValue) {
    if (aIndex < mAmountInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int NorGate::getOutput() {
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
        if (mInput[i] == 1) {
            return 0;
        }
    }
    return 1; // Not a single input was true, so return true
}

void NorGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs){
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for NorGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}