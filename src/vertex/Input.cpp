#include <iostream>

#include "Input.h"

Input Input::m_cInstance("INPUT");

/**
 ************************************************************
 * @brief Default constructor for the Input class
 *
 * Initializes the propagation delay values and sets input limits
 *
 */
Input::Input() {
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 0;

    mValue = -1;
    mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor for the Input class with an ID
 *
 * Associates the Input with an ID, initializes values and sets input limits
 *
 * @param[in] id - The ID of the Input
 */
Input::Input(std::string id) : Vertex(id) {
    mValue = -1;
    mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Destructor for the Input class
 *
 * Cleans up resources used by the Input
 *
 */
Input::~Input() {
    if (mInput != nullptr) {
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Sets the input value for the Input
 *
 * Sets the input value at index 0
 *
 * @param[in] aIndex - The index of the input (should be 0 for Input)
 * @param[in] aValue - The value to set at the specified index
 */
void Input::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Input::setInput error aIndex is not zero" << std::endl;
    }
    if (aIndex < mAmountInputs) {
        mInput[aIndex] = aValue;
    }
    return;
}

/**
 ************************************************************
 * @brief Gets the output value of the Input
 *
 * @return The output value
 */
int Input::getOutput() { return mOutput; }

/**
 ************************************************************
 * @brief Sets the internal value of the Input
 *
 * Sets the value based on the given boolean parameter
 *
 * @param[in] aValue - The boolean value to set (true or false)
 */
void Input::setValue(bool aValue) { mValue = aValue ? 1 : 0; }

/**
 ************************************************************
 * @brief Creates a clone of this Input
 *
 * @return A pointer to the newly cloned Input
 */
Vertex* Input::clone() const { return new Input; }

/**
 ************************************************************
 * @brief Sets the output of the Input
 *
 * Sets the output to the value of the first input and notifies observers
 *
 */
void Input::setOutput() {
    mOutput = mInput[0];
    notify();
}

/**
 ************************************************************
 * @brief Returns a string identifying this class
 *
 * @return A string identifying this class
 */
std::string Input::whoAmI() { return std::string("I am an Input!"); }

/**
 ************************************************************
 * @brief Accepts a visitor for output processing
 *
 * Allows a visitor to process this Input for output purposes
 *
 * @param[inout] aIOutputVisitor - The visitor object for output processing
 * @return An integer result from the visitor's visit method
 */
int Input::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitInput(this); }
