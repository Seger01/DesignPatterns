#include "OrGate.h"
#include <iostream>

OrGate::OrGate() {}

void OrGate::setInput(int aIndex, bool aValue) {
    if (aIndex < mMaxInputs)
        mInput[aIndex] = aValue ? 1 : 0;
}
int OrGate::getOutput() {
    return mMinInputs;
}

void OrGate::setAmountInputs(int aAmount) {
    
}