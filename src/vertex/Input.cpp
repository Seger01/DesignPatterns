#include <iostream>

#include "Input.h"

Input Input::m_cInstance("INPUT");

Input::Input() {
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 0;

    mValue = -1;
    mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

Input::Input(std::string id) : Vertex(id) {
    mValue = -1;
    mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

Input::~Input() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

void Input::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Input::setInput error aIndex is not zero" << std::endl;
    }
    if (aIndex < mAmountInputs) {
        mInput[aIndex] = aValue;
    }
    return;
}

int Input::getOutput() { return mOutput; }

void Input::setValue(bool aValue) { mValue = aValue ? 1 : 0; }

Vertex* Input::clone() const { return new Input; }

void Input::setOutput() {
    mOutput = mInput[0];
    notify();
}

std::string Input::whoAmI() { return std::string("I am an Input!"); }

int Input::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitInput(this); }
