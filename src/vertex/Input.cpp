#pragma once

#include <iostream>

#include "Input.h"

Input::Input(int aStartValue) { mValue = aStartValue; }

void Input::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Input::setInput error aIndex is not zero" << std::endl;
    }

    mValue = aValue;
    return;
}
int Input::getOutput() { return mValue; }
