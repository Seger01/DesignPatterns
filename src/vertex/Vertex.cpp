#include <algorithm>
#include <iostream>

#include "Vertex.h"
#include "VertexFactory.h"

/**
 ************************************************************
 * @brief Default constructor for the Vertex class
 *
 * Initializes the propagation delay values
 *
 */
Vertex::Vertex() {
    mCurrentPropogationDelay = 0;
    mAddingPropagationDelay = 10;
}

/**
 ************************************************************
 * @brief Constructor for the Vertex class with an ID
 *
 * Associates the Vertex with an ID for the VertexFactory
 *
 * @param[in] id - The ID of the Vertex
 */
Vertex::Vertex(std::string id) {
    Factory::VertexFactory<std::string, Vertex>::assign(id, this); // Associate the ID of the child, so the factory
                                                                   // knows which type of child to create
}

/**
 ************************************************************
 * @brief Destructor for the Vertex class
 *
 * Unsubscribes this Vertex from all subjects it is observing
 *
 */
Vertex::~Vertex() {
    if (subjects.size() != 0) {
        for (Vertex* subject : subjects) {
            subject->unsubscribe(this);
        }
    }
}

/**
 ************************************************************
 * @brief Subscribes an observer to this Vertex
 *
 * Adds the observer to the list of observers
 *
 * @param[in] observer - The Vertex to be subscribed as an observer
 */
void Vertex::subscribe(Vertex* observer) {
    if (observer == nullptr) {
        std::cout << "Vertex::subscribe received nullptr" << std::endl;
        // return;
    }

    observers.push_back(observer);
}

/**
 ************************************************************
 * @brief Unsubscribes an observer from this Vertex
 *
 * Removes the observer from the list of observers
 *
 * @param[in] observer - The Vertex to be unsubscribed
 */
void Vertex::unsubscribe(Vertex* observer) {
    if (observers.size() == 0) {
        return;
    }
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

/**
 ************************************************************
 * @brief Adds a subject to this Vertex
 *
 * Adds the subject to the list of subjects and subscribes this Vertex as an observer
 *
 * @param[in] subject - The Vertex to be added as a subject
 */
void Vertex::addSubject(Vertex* subject) {
    if (subject == nullptr) {
        std::cout << "addSubject received nullptr" << std::endl;
    }
    subjects.push_back(subject);
    subject->subscribe(this);
}

/**
 ************************************************************
 * @brief Removes a subject from this Vertex
 *
 * Removes the subject from the list of subjects and unsubscribes this Vertex as an observer
 *
 * @param[in] subject - The Vertex to be removed as a subject
 */
void Vertex::removeSubject(Vertex* subject) {
    subjects.erase(std::remove(subjects.begin(), subjects.end(), subject), subjects.end());
    subject->unsubscribe(this);
}

/**
 ************************************************************
 * @brief Notifies all observers of a state change
 *
 * Calls the update method on each observer
 *
 */
void Vertex::notify() {
    for (Vertex* observer : observers) {
        observer->update();
    }
}

/**
 ************************************************************
 * @brief Sets the state of this Vertex
 *
 * Sets the internal state and notifies observers of the change
 *
 * @param[in] state - The new state of the Vertex
 */
void Vertex::setState(int state) {
    this->state = state;
    notify();
}

/**
 ************************************************************
 * @brief Sets the input value for a specified index
 *
 * Sets the input value at the specified index and notifies observers
 *
 * @param[in] aIndex - The index of the input
 * @param[in] value - The value to set at the specified index
 */
void Vertex::setInput(int aIndex, int value) {
    if (aIndex < mAmountInputs) {
        mInput[aIndex] = value;
    }
    notify();
    return;
}

/**
 ************************************************************
 * @brief Gets the output value of this Vertex
 *
 * @return The output value
 */
int Vertex::getOutput() { return mOutput; }

/**
 ************************************************************
 * @brief Gets the propagation delay of this Vertex
 *
 * Calculates the highest propagation delay from the subjects and adds the additional delay
 *
 * @return The total propagation delay
 */
int Vertex::getPropagationDelay() {
    int highestDelay = 0;
    for (int i = 0; i < subjects.size(); i++) {
        int subjectPropagationDelay = subjects[i]->getPropagationDelay();

        if (subjectPropagationDelay > highestDelay) {
            highestDelay = subjectPropagationDelay;
        }
    }

    return highestDelay + mAddingPropagationDelay;
}

/**
 ************************************************************
 * @brief Updates the state of this Vertex based on its subjects
 *
 * Sets the input values based on the outputs of the subjects
 *
 */
void Vertex::update() {
    for (int i = 0; i < subjects.size(); i++) {
        this->setInput(i, subjects[i]->getOutput());
    }
}

/**
 ************************************************************
 * @brief Increases the number of inputs for this Vertex
 *
 * Increments the input count if it does not exceed the maximum allowed inputs
 *
 * @return 0 if successful, -1 if the maximum number of inputs is reached
 */
int Vertex::bumpAmountInputs() {
    if (mAmountInputs >= (int)mMaxInputs) {
        std::cout << "Cannot increase amount of inputs for vertex, " << mAmountInputs << " already set!" << std::endl;
        return -1;
    }
    if (mAmountInputs == -1) {
        mAmountInputs = 0;
    }
    mAmountInputs++;
    return 0;
}

/**
 ************************************************************
 * @brief Returns a string identifying this class
 *
 * @return A string identifying this class
 */
std::string Vertex::whoAmI() { return std::string("I am a Vertex!"); }
