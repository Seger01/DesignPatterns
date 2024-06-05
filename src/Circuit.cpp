#include "Circuit.h"
#include "OutputVisitor.h"

Circuit* Circuit::mCircuit = nullptr;

/**
 ************************************************************
 * @brief Destructor for the Circuit class
 *
 * Deletes all Vertex pointers stored in the mMapVertexes map to free allocated memory
 *
 */
Circuit::~Circuit() {
    for (std::map<std::string, Vertex*>::iterator iterator = mMapVertexes.begin(); iterator != mMapVertexes.end();
         ++iterator) {
        if (iterator->second != nullptr) { // Check for nullptr
            delete iterator->second;
        }
    }
}

/**
 ************************************************************
 * @brief Gets the singleton instance of the Circuit class
 *
 * Ensures that only one instance of the Circuit class exists.
 * If the instance does not exist, it creates one.
 *
 * @return Reference to the singleton instance of the Circuit class
 */
Circuit& Circuit::getInstance() {
    if (mCircuit == nullptr) {
        mCircuit = new Circuit;
    }

    return *mCircuit;
}

/**
 ************************************************************
 * @brief Gets the map of vertexes
 *
 * Returns a reference to the map that stores vertexes
 *
 * @return Reference to the map of vertexes
 */
std::map<std::string, Vertex*>& Circuit::getVertexMap() { return mMapVertexes; }

/**
 ************************************************************
 * @brief Runs the simulation on the circuit
 *
 * Iterates through the map of vertexes and sets the output for each vertex
 * that is identified as an input by the OutputVisitor
 *
 */
void Circuit::runSim() {
    OutputVisitor outputVisitor;

    for (std::map<std::string, Vertex*>::iterator iterator = mMapVertexes.begin(); iterator != mMapVertexes.end();
         ++iterator) {
        if (iterator->second != nullptr) {                                   // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 1) { // Check if it is an input
                iterator->second->setOutput();
            }
        }
    }
    return;
}
