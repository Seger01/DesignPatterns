#include <iostream>

#include "Input.h"

Input Input::m_cInstance("INPUT");

Input::Input() {
    std::cout << "Input default constructor" << std::endl;
    mValue = -1;
}

Input::Input(std::string id) : Vertex(id) {
    std::cout << "Input assignment constructor" << std::endl;
    mValue = -1;
}

Input::~Input() { std::cout << "Input destructor" << std::endl; }

// void Input::setInput(int aIndex, int aValue) {
//     std::cout << "Input::setInput" << std::endl;
//     if (aIndex != 0) {
//         std::cout << "Input::setInput error aIndex is not zero" << std::endl;
//     }
//
//     mValue = aValue;
//     mOutput = aValue;
//     return;
// }
int Input::getOutput() {
    std::cout << "Input::getOutput()" << std::endl;

    return mOutput;
}

void Input::setValue(bool aValue) { mValue = aValue ? 1 : 0; }

Vertex* Input::clone() const { return new Input; }

std::string Input::whoAmI() { return std::string("I am an Input!"); }

int Input::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitInput(this); }
