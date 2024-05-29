#include "CircuitInitializer.h"

#include "Circuit.h"
#include "Input.h"
#include "Vertex.h"

#include <cmath>

CircuitInitializer::CircuitInitializer(/* args */) { this->mIteration = 0; }

CircuitInitializer::~CircuitInitializer() {}

void CircuitInitializer::fillInputs() {
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        // Use dynamic_cast to check if the Vertex is an instance of Input
        if (dynamic_cast<Input*>(iterator->second)) {
            // If the cast is correct, it is an Input
            if (iterator->second->getOutput() == -1) {
                this->mInputs.push_back(iterator->second);
            }
        }
    }
}

void CircuitInitializer::setInputs() {
    int numOfInputs = this->mInputs.size();
    for (int i = 0; i < numOfInputs; i++) {
        // Determine the value to set based on the iteration and position
        bool value = (mIteration >> i) & 1;
        mInputs[i]->setInput(0, value);
    }
    mIteration++;
}

void CircuitInitializer::initCircuit() {

    if (this->mIteration == 0) {
        CircuitInitializer::fillInputs();
    }
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        // Use dynamic_cast to check if the Vertex is an instance of Input
        if (!dynamic_cast<Input*>(iterator->second)) {
            // If the cast is correct, it is not an Input
            // iterator->second->reset();
        }
    }

    setInputs();
}
