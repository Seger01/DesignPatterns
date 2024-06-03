#include "CircuitInitializer.h"

#include "Circuit.h"
#include "Input.h"
#include "Vertex.h"
#include "OutputVisitor.h"

#include <cmath>

CircuitInitializer::CircuitInitializer(/* args */) { this->mIteration = 0; }

CircuitInitializer::~CircuitInitializer() {}

void CircuitInitializer::fillInputs() {
    OutputVisitor outputVisitor;
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second->acceptOutputVisitor(outputVisitor) == 1) {//check if it is an input
            if (iterator->second->getOutput() == -1) {  //check if it is an undefined input
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
    OutputVisitor outputVisitor;

    if (this->mIteration == 0) {
        CircuitInitializer::fillInputs();
    }
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second->acceptOutputVisitor(outputVisitor) == 2 || iterator->second->acceptOutputVisitor(outputVisitor) == 3) { //Check if it is an probe or gate
            iterator->second->reset();
        }
    }

    setInputs();
}
