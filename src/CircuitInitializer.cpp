/**
 ************************************************************
 * @file CircuitInitializer.cpp
 *
 * Implements the CircuitInitializer class for initializing and managing
 * circuit inputs and iteration state.
 *
 * @author Sean Groenenboom
 * @date June 4, 2024
 */
#include "CircuitInitializer.h"

#include "Circuit.h"
#include "Input.h"
#include "OutputVisitor.h"
#include "Vertex.h"

#include <cmath>

/**
 ************************************************************
 * @brief Constructor for CircuitInitializer
 *
 * Initializes the CircuitInitializer object and sets the iteration to 0.
 */
CircuitInitializer::CircuitInitializer() { this->mIteration = 0; }

/**
 ************************************************************
 * @brief Destructor for CircuitInitializer
 *
 * Cleans up resources used by the CircuitInitializer object.
 */
CircuitInitializer::~CircuitInitializer() {}

/**
 ************************************************************
 * @brief Fills the inputs from the vertex map
 *
 * Populates the mInputs vector with vertices that are inputs.
 *
 * @param[in] aVertexMap - Map of vertex names to types
 */
void CircuitInitializer::fillInputs(std::map<std::string, std::string>& aVertexMap) {
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, std::string>::iterator iterator = aVertexMap.begin(); iterator != aVertexMap.end();
         iterator++) {
        if (iterator->second == "INPUT") {                                                  // Vertex is undefined input
            std::map<std::string, Vertex*>::iterator dataIter = data.find(iterator->first); // Get iterator at name of
                                                                                            // input
            if (dataIter != data.end()) {          // Check if the input with id iterator->first exists
                Vertex* vertex = dataIter->second; // If it exists, get the pointer to its vertex object
                this->mInputs.push_back(vertex);   // Add it to the inputs
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

/**
 ************************************************************
 * @brief Sets the input values for the circuit
 *
 * Sets the input values for the circuit based on the current iteration.
 */
void CircuitInitializer::setInputs() {
    int numOfInputs = this->mInputs.size();
    for (int i = 0; i < numOfInputs; i++) {
        // Determine the value to set based on the iteration and position
        bool value = (mIteration >> i) & 1;
        mInputs[i]->setInput(0, (int)value);
    }
    mIteration++;
}

/**
 ************************************************************
 * @brief Initializes the circuit
 *
 * Resets the circuit and sets the input values for the circuit.
 *
 * @param[in] aVertexMap - Map of vertex names to types
 */
void CircuitInitializer::initCircuit(std::map<std::string, std::string>& aVertexMap) {
    OutputVisitor outputVisitor;

    if (this->mIteration == 0) {
        CircuitInitializer::fillInputs(aVertexMap);
    }

    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second != nullptr) { // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 2 ||
                iterator->second->acceptOutputVisitor(outputVisitor) == 3) { // Check if it is a probe or gate
                iterator->second->reset();
            }
        }
    }

    setInputs();
}