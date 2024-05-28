#pragma once

#include <iostream>

#include "Probe.h"

void Probe::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Probe setInput error aIndex supposed to be 0 but is: " << aIndex << std::endl;
        return;
    }

    mValue = aValue;
    this->notify();
    return;
}
bool Probe::getValue() { return mValue; }
