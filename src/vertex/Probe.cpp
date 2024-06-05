#include <iostream>

#include "IOutputVisitor.h"
#include "Probe.h"

Probe Probe::m_cInstance("PROBE");

/**
 ************************************************************
 * @brief Default constructor for the Probe class
 *
 * Initializes the propagation delay values and sets input limits
 *
 */
Probe::Probe() {
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 0;

    // mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Constructor for the Probe class with an ID
 *
 * Associates the Probe with an ID, initializes values and sets input limits
 *
 * @param[in] id - The ID of the Probe
 */
Probe::Probe(std::string id) : Vertex(id) {
    mValue = -1;
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 0;

    // mAmountInputs = 1;
    mMinInputs = 1;
    mMaxInputs = 1;
    mInput = new int[mMaxInputs];
}

/**
 ************************************************************
 * @brief Destructor for the Probe class
 *
 * Cleans up resources used by the Probe
 *
 */
Probe::~Probe() {
    if(mInput != nullptr){
        delete[] mInput;
    }
}

/**
 ************************************************************
 * @brief Sets the input value for the Probe
 *
 * Sets the input value at index 0 and notifies observers of the change
 *
 * @param[in] aIndex - The index of the input (should be 0 for Probe)
 * @param[in] aValue - The value to set at the specified index
 */
void Probe::setInput(int aIndex, int aValue) {
    if (aIndex != 0) {
        std::cout << "Probe setInput error aIndex supposed to be 0 but is: " << aIndex << std::endl;
        return;
    }

    mValue = aValue;
    this->notify();
    return;
}

/**
 ************************************************************
 * @brief Gets the current value of the Probe
 *
 * @return The current value of the Probe
 */
int Probe::getValue() { return mValue; }

/**
 ************************************************************
 * @brief Gets the output value of the Probe
 *
 * @return The output value, which is the same as the current value
 */
int Probe::getOutput() { return mValue; }

/**
 ************************************************************
 * @brief Creates a clone of this Probe
 *
 * @return A pointer to the newly cloned Probe
 */
Vertex* Probe::clone() const { return new Probe; }

/**
 ************************************************************
 * @brief Returns a string identifying this class
 *
 * @return A string identifying this class
 */
std::string Probe::whoAmI() { return std::string("I am a Probe!"); }

/**
 ************************************************************
 * @brief Accepts a visitor for output processing
 *
 * Allows a visitor to process this Probe for output purposes
 *
 * @param[inout] aIOutputVisitor - The visitor object for output processing
 * @return An integer result from the visitor's visit method
 */
int Probe::acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return aIOutputVisitor.visitProbe(this); }
