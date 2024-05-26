#include "CircuitInitializer.h"

#include "Input.h"
#include "Vertex.h"

#include <cmath>

CircuitInitializer::CircuitInitializer(/* args */) { this->mIteration = 0; }

CircuitInitializer::~CircuitInitializer() {}

void CircuitInitializer::fillInputs(std::map<std::string, Vertex*>& aCircuit) {
    for (const auto& pair : aCircuit) {
        //Use dynamic_cast to check if the Vertex is an instance of Input
        // Input* inputPtr = dynamic_cast<Input*>(pair.second);
        // if (inputPtr) {
        //     // If the cast is correct, it is an Input
        //     if (inputPtr->getInput() == -1) {
        //         this->mInputs.insert(inputPtr);
        //     }
        // }
    }
}

void CircuitInitializer::setInputs() {
    int numOfInputs = this->mInputs.size();
    for (int i = 0; i < numOfInputs; i++) {
        // Determine the value to set based on the iteration and position
        bool value = (mIteration >> i) & 1;
        mInputs[i]->setInput(value);
    }
    mIteration++;
}

void CircuitInitializer::initCircuit(std::map<std::string, Vertex*>& aCircuit) {

    if (this->mIteration == 0) {
        CircuitInitializer::fillInputs(aCircuit);
    }

    setInputs();

    for (const auto& pair : aCircuit) {
        // Use dynamic_cast to check if the Vertex is an instance of Input
        // Input* inputPtr = dynamic_cast<Input*>(pair.second);
        // if (!inputPtr) {
        //     // If the cast fails, it is not an Input, so call reset
        //     pair.second->reset();
        // }
    }
}