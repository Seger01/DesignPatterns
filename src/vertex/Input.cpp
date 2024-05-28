#pragma once

#include <iostream>

#include "Input.h"

void Input::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Input::setInput error aIndex is not zero" << std::endl;
    }

    mValue = aValue;
    return;
}
int Input::getOutput() { return mValue; }

Input Input::m_cInstance(7);

Input::Input() {
    std::cout << "Input default constructor" << std::endl;
    mValue = -1;
}

Input::Input(int id) : Vertex(id) {
    std::cout << "Input assignment constructor" << std::endl;
    mValue = -1;
}

Input::~Input() { std::cout << "Input destructor" << std::endl; }

void Input::setValue(bool aValue) { mValue = aValue ? 1 : 0; }

Vertex* Input::clone() const { return new Input; }
