/**
 ************************************************************
 * @file NotGate.cpp
 *
 * This file contains the implementation of the NotGate class, which represents
 * a logical NOT gate with a single input.
 *
 */

#include "NotGate.h"
#include <iostream>

/**
 ************************************************************
 * @brief Instance of NotGate
 *
 * This is the instance of the NotGate class, required by the factory, initialized with the ID "NOT".
 */
NotGate NotGate::m_cInstance("NOT");

/**
 ************************************************************
 * @brief Default constructor
 *
 * Initializes a NotGate with default values. Sets the minimum and maximum
 * number of inputs to 1 and allocates memory for the input.
 */
NotGate::NotGate() {
    mAmountInputs = -1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor with ID
 *
 * Initializes a NotGate with a specific ID. Sets the minimum and maximum
 * number of inputs to 1 and allocates memory for the input.
 *
 * @param[in] id - The identifier for the NotGate instance
 */
NotGate::NotGate(std::string id) : Vertex(id) {
    mAmountInputs = -1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Destructor
 *
 * Cleans up the allocated memory for the input.
 */
NotGate::~NotGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Get the output of the NOT gate
 *
 * Computes the logical NOT of the input. If the input is not set, it outputs an error message.
 *
 * @return The output of the NOT gate (1 for true, 0 for false, -1 for error)
 */
int NotGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to NOT gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: " << mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (mInput[0] == -1) {
        // std::cout << "Input not set yet!" << std::endl;
        return -1;
    }
    if (mInput[0] == 0) {
        return 1;
    }
    return 0; // Input was not zero, so return 1
}

/**
 ************************************************************
 * @brief Set the number of inputs
 *
 * Configures the number of inputs for the NOT gate. Outputs an error message
 * if the provided amount is outside the valid range.
 *
 * @param[in] aAmount - The number of inputs to set
 */
void NotGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for NotGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

/**
 ************************************************************
 * @brief Clone the NotGate instance
 *
 * Creates a new instance of NotGate with the same properties.
 *
 * @return A pointer to the newly cloned NotGate instance
 */
Vertex* NotGate::clone() const { return new NotGate; }

/**
 ************************************************************
 * @brief Identify the object type
 *
 * Provides a string description of the object.
 *
 * @return A string "I am a NotGate!"
 */
std::string NotGate::whoAmI() { return std::string("I am a NotGate!"); }

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
int NotGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
