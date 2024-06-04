#include "CircuitInitializer.h"

#include "Circuit.h"
#include "Input.h"
#include "OutputVisitor.h"
#include "Vertex.h"

#include <cmath>

CircuitInitializer::CircuitInitializer(/* args */) { this->mIteration = 0; }

CircuitInitializer::~CircuitInitializer() {}

void CircuitInitializer::fillInputs(std::map<std::string, std::string>& aVertexMap) {

    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, std::string>::iterator iterator = aVertexMap.begin(); iterator != aVertexMap.end();
         iterator++) {
        if (iterator->second == "INPUT") {                       // Vertex is undefined input
            Vertex* vertex = data.find(iterator->first)->second; // Find Vertex in the map
            if (vertex != data.end()->second) {                  // Check if it exists
                this->mInputs.push_back(vertex);
            }
        }
        if (iterator->second == "INPUT_HIGH") {                  // Vertex is input high
            Vertex* vertex = data.find(iterator->first)->second; // Find Vertex in the map
            if (vertex != data.end()->second) {                  // Check if it exists
                vertex->setInput(0, 1);
            }
        }
        if (iterator->second == "INPUT_LOW") {                   // Vertex is input low
            Vertex* vertex = data.find(iterator->first)->second; // Find Vertex in the map
            if (vertex != data.end()->second) {                  // Check if it exists
                vertex->setInput(0, 0);
            }
        }
    }
}

void CircuitInitializer::setInputs() {
    int numOfInputs = this->mInputs.size();
    for (int i = 0; i < numOfInputs; i++) {
        // Determine the value to set based on the iteration and position
        bool value = (mIteration >> i) & 1;
        mInputs[i]->setInput(0, (int)value);
    }
    mIteration++;
}

void CircuitInitializer::initCircuit(std::map<std::string, std::string>& aVertexMap) {
    OutputVisitor outputVisitor;

    if (this->mIteration == 0) {
        CircuitInitializer::fillInputs(aVertexMap);
    }
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second != nullptr) { // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 2 ||
                iterator->second->acceptOutputVisitor(outputVisitor) == 3) { // Check if it is an probe or gate
                iterator->second->reset();
            }
        }
    }

    setInputs();
}
