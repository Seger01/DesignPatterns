#include "NotGate.h"
#include <iostream>

NotGate::NotGate() {
    mAmountInputs = -1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

NotGate::~NotGate() {
    if (mInput != nullptr) {
        delete mInput;
    }
}

void NotGate::setInput(unsigned aIndex, bool aValue) {
    if (aIndex < mAmountInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int NotGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mInput[0] == -1) {
        std::cout << "Input not set yet!" << std::endl;
        return -1;
    }
    if (mInput[0] == 0) {
        return 1;
    }
    return 0; // Input was not zero, so return 1
}

void NotGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs){
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for NotGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}