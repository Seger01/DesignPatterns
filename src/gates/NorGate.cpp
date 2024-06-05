/**
 ************************************************************
 * @file NorGate.cpp
 *
 * This file contains the implementation of the NorGate class, which represents
 * a logical NOR gate with a configurable number of inputs.
 *
 */

#include "NorGate.h"
#include <iostream>

/**
 ************************************************************
 * @brief Instance of NorGate
 *
 * This is the instance of the NorGate class, required by the factory, initialized with the ID "NOR".
 */
NorGate NorGate::m_cInstance("NOR");

/**
 ************************************************************
 * @brief Default constructor
 *
 * Initializes a NorGate with default values. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 */
NorGate::NorGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor with ID
 *
 * Initializes a NorGate with a specific ID. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 *
 * @param[in] id - The identifier for the NorGate instance
 */
NorGate::NorGate(std::string id) : Vertex(id) {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Destructor
 *
 * Cleans up the allocated memory for inputs.
 */
NorGate::~NorGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Get the output of the NOR gate
 *
 * Computes the logical NOR of all connected inputs. If the amount of inputs
 * is not set or if not enough inputs are connected, it outputs an error message.
 *
 * @return The output of the NOR gate (1 for true, 0 for false, -1 for error)
 */
int NorGate::getOutput() {
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to NOR gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: " << mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            // std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 1) {
            return 0;
        }
    }
    return 1; // Not a single input was true, so return true
}

/**
 ************************************************************
 * @brief Set the number of inputs
 *
 * Configures the number of inputs for the NOR gate. Outputs an error message
 * if the provided amount is outside the valid range.
 *
 * @param[in] aAmount - The number of inputs to set
 */
void NorGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for NorGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

/**
 ************************************************************
 * @brief Clone the NorGate instance
 *
 * Creates a new instance of NorGate with the same properties.
 *
 * @return A pointer to the newly cloned NorGate instance
 */
Vertex* NorGate::clone() const { return new NorGate; }

/**
 ************************************************************
 * @brief Identify the object type
 *
 * Provides a string description of the object.
 *
 * @return A string "I am a NorGate!"
 */
std::string NorGate::whoAmI() { return std::string("I am a NorGate!"); }

/**
 ************************************************************
 * @brief Accept an output visitor
 *
 * Accepts a visitor object that implements the IOutputVisitor interface.
 *
 * @param[inout] aIOutputVisitor - The visitor object
 *
 * @return The result of the visitor's visitVertex method
 */
int NorGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
