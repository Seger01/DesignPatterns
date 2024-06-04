/**
 ************************************************************
 * @file AndGate.cpp
 *
 * This file contains the implementation of the AndGate class, which represents
 * a logical AND gate with a configurable number of inputs.
 *
 */

#include "AndGate.h"
#include <iostream>

/**
 ************************************************************
 * @brief Instance of AndGate
 *
 * This is the instance of the AndGate class, required by the factory, initialized with the ID "AND".
 */
AndGate AndGate::m_cInstance("AND");

/**
 ************************************************************
 * @brief Default constructor
 *
 * Initializes an AndGate with default values. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 */
AndGate::AndGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor with ID
 *
 * Initializes an AndGate with a specific ID. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 *
 * @param[in] id - The identifier for the AndGate instance
 */
AndGate::AndGate(std::string id) : Vertex(id) {
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
AndGate::~AndGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Get the output of the AND gate
 *
 * Computes the logical AND of all connected inputs. If the amount of inputs
 * is not set or if not enough inputs are connected, it outputs an error message.
 *
 * @return The output of the AND gate (1 for true, 0 for false, -1 for error)
 */
int AndGate::getOutput() {
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to AND gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: " << mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            // std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 0) {
            return 0;
        }
    }
    return 1; // Not a single input was false, so return true
}

/**
 ************************************************************
 * @brief Set the number of inputs
 *
 * Configures the number of inputs for the AND gate. Outputs an error message
 * if the provided amount is outside the valid range.
 *
 * @param[in] aAmount - The number of inputs to set
 */
void AndGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for andgate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

/**
 ************************************************************
 * @brief Clone the AndGate instance
 *
 * Creates a new instance of AndGate with the same properties.
 *
 * @return A pointer to the newly cloned AndGate instance
 */
Vertex* AndGate::clone() const { return new AndGate; }

/**
 ************************************************************
 * @brief Identify the object type
 *
 * Provides a string description of the object.
 *
 * @return A string "I am an AndGate!"
 */
std::string AndGate::whoAmI() { return std::string("I am an AndGate!"); }

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
int AndGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
