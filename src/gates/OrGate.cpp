#include "OrGate.h"
#include <iostream>

OrGate::OrGate() {
    mInput = new int[mMaxInputs];
}

void OrGate::setInput(int aIndex, bool aValue) {
    if (aIndex < mAmountInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int OrGate::getOutput() {
    bool output = false;
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

void OrGate::setAmountInputs(int aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs){
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for orgate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}