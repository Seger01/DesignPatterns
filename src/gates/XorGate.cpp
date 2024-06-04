/**
 ************************************************************
 * @file XorGate.cpp
 *
 * This file contains the implementation of the XorGate class, which represents
 * a logical XOR gate with two inputs.
 *
 */

#include "XorGate.h"
#include <iostream>

/**
 ************************************************************
 * @brief Instance of XorGate
 *
 * This is the instance of the XorGate class, required by the factory, initialized with the ID "XOR".
 */
XorGate XorGate::m_cInstance("XOR");

/**
 ************************************************************
 * @brief Default constructor
 *
 * Initializes an XorGate with default values. Sets the minimum and maximum
 * number of inputs to 2 and allocates memory for the inputs.
 */
XorGate::XorGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 2;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor with ID
 *
 * Initializes an XorGate with a specific ID. Sets the minimum and maximum
 * number of inputs to 2 and allocates memory for the inputs.
 *
 * @param[in] id - The identifier for the XorGate instance
 */
XorGate::XorGate(std::string id) : Vertex(id) {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 2;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Destructor
 *
 * Cleans up the allocated memory for inputs.
 */
XorGate::~XorGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Get the output of the XOR gate
 *
 * Computes the logical XOR of the two connected inputs. If the amount of inputs
 * is not set or if not enough inputs are connected, it outputs an error message.
 *
 * @return The output of the XOR gate (1 for true, 0 for false, -1 for error)
 */
int XorGate::getOutput() {
    bool output = false;
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to XOR gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: " << mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (mInput[0] == -1 || mInput[1] == -1) {
        // std::cout << "Inputs not set yet!" << std::endl;
        return -1;
    }
    if (mInput[0] == 1 && mInput[1] == 1) {
        return 0;
    }
    if (mInput[0] == 0 && mInput[1] == 0) {
        return 0;
    }
    return 1; // Not a single input was true, so return false
}

/**
 ************************************************************
 * @brief Set the number of inputs
 *
 * Configures the number of inputs for the XOR gate. Outputs an error message
 * if the provided amount is outside the accepted range.
 *
 * @param[in] aAmount - The number of inputs to set
 */
void XorGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for XorGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

/**
 ************************************************************
 * @brief Clone the XorGate instance
 *
 * Creates a new instance of XorGate with the same properties.
 *
 * @return A pointer to the newly cloned XorGate instance
 */
Vertex* XorGate::clone() const { return new XorGate; }

/**
 ************************************************************
 * @brief Identify the object type
 *
 * Provides a string description of the object.
 *
 * @return A string "I am an XorGate!"
 */
std::string XorGate::whoAmI() { return std::string("I am an XorGate!"); }

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
int XorGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
