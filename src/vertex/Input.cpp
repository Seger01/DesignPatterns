#include <iostream>

#include "Input.h"

Input Input::m_cInstance("INPUT");

Input::Input() {
    std::cout << "Input default constructor" << std::endl;
    mValue = -1;
    mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

Input::Input(std::string id) : Vertex(id) {
    std::cout << "Input assignment constructor" << std::endl;
    mValue = -1;
    mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

Input::~Input() { std::cout << "Input destructor" << std::endl; }

void Input::setInput(int aIndex, int aValue) {

    std::cout << "VInput::setInput: " << mAmountInputs << std::endl;
    // std::cout << "setInput " << aIndex << ", " << value << std::endl;
    // mOutput = value;
    if (aIndex != 0) {
        std::cout << "Input::setInput error aIndex is not zero" << std::endl;
    }
    if (aIndex < mAmountInputs) {
        mInput[aIndex] = aValue;
    }
    return;
}

int Input::getOutput() {
    std::cout << "Input::getOutput()" << std::endl;

    return mOutput;
}

void Input::setValue(bool aValue) { mValue = aValue ? 1 : 0; }

Vertex* Input::clone() const { return new Input; }

void Input::setOutput(){
    mOutput = mInput[0];
    notify();
}

std::string Input::whoAmI() { return std::string("I am an Input!"); }

int Input::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitInput(this); }
