#include "Input.h"
#include <iostream>

Input Input::m_cInstance(7);

Input::Input() {
    std::cout << "Input default constructor" << std::endl;
    mValue = -1;
}

Input::Input(int id) : Vertex(id) {
    std::cout << "Input assignment constructor" << std::endl;
    mValue = -1;
}

Input::~Input() {
    std::cout << "Input destructor" << std::endl;
}

int Input::getOutput() {
    return mValue;
}

void Input::setValue(bool aValue) {
    mValue = aValue ? 1 : 0;
}

Vertex *Input::clone() const {
    return new Input;
}