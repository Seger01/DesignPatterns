/**
 ************************************************************
 * @file NandGate.cpp
 *
 * This file contains the implementation of the NandGate class, which represents
 * a logical NAND gate with a configurable number of inputs.
 *
 */

#include "NandGate.h"
#include <iostream>

/**
 ************************************************************
 * @brief Instance of NandGate
 *
 * This is the instance of the NandGate class, required by the factory, initialized with the ID "NAND".
 */
NandGate NandGate::m_cInstance("NAND");

/**
 ************************************************************
 * @brief Default constructor
 *
 * Initializes a NandGate with default values. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 */
NandGate::NandGate() {
    mAmountInputs = -1;
    mMinInputs = 2;
    mMaxInputs = 3;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor with ID
 *
 * Initializes a NandGate with a specific ID. Sets the minimum and maximum
 * number of inputs and allocates memory for the inputs.
 *
 * @param[in] id - The identifier for the NandGate instance
 */
NandGate::NandGate(std::string id) : Vertex(id) {
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
NandGate::~NandGate() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Get the output of the NAND gate
 *
 * Computes the logical NAND of all connected inputs. If the amount of inputs
 * is not set or if not enough inputs are connected, it outputs an error message.
 *
 * @return The output of the NAND gate (1 for true, 0 for false, -1 for error)
 */
int NandGate::getOutput() {
    if (mAmountInputs < 0) {
        std::cout << "Amount of inputs not set!" << std::endl;
        return -1;
    }
    if (mAmountInputs < mMinInputs) {
        std::cout << "Not enough inputs connected to NAND gate" << std::endl;
        std::cout << "Minimum inputs: " << mMinInputs << "\tInputs connected are: " << mAmountInputs << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mAmountInputs; i++) {
        if (mInput[i] == -1) {
            // std::cout << "Input at index " << i << " not set yet!" << std::endl;
            return -1;
        }
        if (mInput[i] == 0) {
            return 1;
        }
    }
    return 0; // Not a single input was true, so return false
}

/**
 ************************************************************
 * @brief Set the number of inputs
 *
 * Configures the number of inputs for the NAND gate. Outputs an error message
 * if the provided amount is outside the valid range.
 *
 * @param[in] aAmount - The number of inputs to set
 */
void NandGate::setAmountInputs(unsigned aAmount) {
    if (aAmount < mMinInputs || aAmount > mMaxInputs) {
        std::cout << "Error: invalid amount of inputs (" << aAmount << ") for NandGate" << std::endl;
        return;
    }
    mAmountInputs = aAmount;
}

/**
 ************************************************************
 * @brief Clone the NandGate instance
 *
 * Creates a new instance of NandGate with the same properties.
 *
 * @return A pointer to the newly cloned NandGate instance
 */
Vertex* NandGate::clone() const { return new NandGate; }

/**
 ************************************************************
 * @brief Identify the object type
 *
 * Provides a string description of the object.
 *
 * @return A string "I am a NandGate!"
 */
std::string NandGate::whoAmI() { return std::string("I am a NandGate!"); }

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
int NandGate::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitVertex(this); }
