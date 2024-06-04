/**
 ************************************************************
 * @file OrGate.cpp
 *
 * This file contains the implementation of the OrGate class, which represents
 * a logical OR gate with a configurable number of inputs.
 *
 */

#include "OrGate.h"
#include <iostream>

/**
 ************************************************************
 * @brief Instance of OrGate
 *
 * This is the instance of the OrGate class, required by the factory, initialized with the ID "OR".
 */
OrGate OrGate::m_cInstance("OR");

/**
 ************************************************************
 * @brief Default constructor
 *
 * Initializes an OrGate with default values. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 */
OrGate::OrGate() {
    mInput = new int[mMaxInputs];
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
}

/**
 ************************************************************
 * @brief Constructor with ID
 *
 * Initializes an OrGate with a specific ID. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 *
 * @param[in] id - The identifier for the OrGate instance
 */
OrGate::OrGate(std::string id) : Vertex(id) {
    mInput = new int[mMaxInputs];
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
}

/**
 ************************************************************
 * @brief Destructor
 *
 * Cleans up the allocated memory for inputs.
 */
OrGate::~OrGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Get the output of the OR gate
 *
 * Computes the logical OR of all connected inputs. If the amount of inputs
 * is not set or if not enough inputs are connected, it outputs an error message.
 *
 * @return The output of the OR gate (1 for true, 0 for false, -1 for error)
 */
int OrGate::getOutput() {
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to OR gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: " << mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            // std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 1) {
            return 1;
        }
    }
    return 0; // Not a single input was true, so return false
}

/**
 ************************************************************
 * @brief Set the number of inputs
 *
 * Configures the number of inputs for the OR gate. Outputs an error message
 * if the provided amount is outside the valid range.
 *
 * @param[in] aAmount - The number of inputs to set
 */
void OrGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for OrGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

/**
 ************************************************************
 * @brief Clone the OrGate instance
 *
 * Creates a new instance of OrGate with the same properties.
 *
 * @return A pointer to the newly cloned OrGate instance
 */
Vertex* OrGate::clone() const { return new OrGate; }

/**
 ************************************************************
 * @brief Identify the object type
 *
 * Provides a string description of the object.
 *
 * @return A string "I am an OrGate!"
 */
std::string OrGate::whoAmI() { return std::string("I am an OrGate!"); }

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
int OrGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
