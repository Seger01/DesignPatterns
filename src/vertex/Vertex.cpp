#include <algorithm>
#include <iostream>

#include "Vertex.h"
#include "VertexFactory.h"

Vertex::Vertex() {}

Vertex::Vertex(std::string id) {
    Factory::VertexFactory<std::string, Vertex>::assign(id, this); // Associate the ID of the child, so the factory
                                                                   // knows which type of child to create
}

Vertex::~Vertex() {
    if (subjects.size() != 0) {
        for (Vertex* subject : subjects) {
            subject->unsubscribe(this);
        }
    }
}

void Vertex::subscribe(Vertex* observer) {
    if (observer == nullptr) {
        std::cout << "Vertex::subscribe received nullptr" << std::endl;
        // return;
    }

    observers.push_back(observer);
}

void Vertex::unsubscribe(Vertex* observer) {
    if (observers.size() == 0) {
        return;
    }
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Vertex::addSubject(Vertex* subject) {
    if (subject == nullptr) {
        std::cout << "addSubject received nullptr" << std::endl;
    }
    subjects.push_back(subject);
    subject->subscribe(this);
}

void Vertex::removeSubject(Vertex* subject) {
    subjects.erase(std::remove(subjects.begin(), subjects.end(), subject), subjects.end());
    subject->unsubscribe(this);
}
void Vertex::notify() {
    for (Vertex* observer : observers) {
        observer->update();
    }
}

void Vertex::setState(int state) {
    this->state = state;
    notify();
}

void Vertex::setInput(int aIndex, int value) {
    if (aIndex < mAmountInputs) {
        mInput[aIndex] = value;
    }
    notify();
    return;
}
// void Vertex::setInput(unsigned aIndex, bool aValue) {
//     if (aIndex < mAmountInputs)
//         mInput[aIndex] = aValue ? 1 : 0;
//     notify();
// }

int Vertex::getOutput() {
    // mOutput = mInput[0];

    return mOutput;
}

void Vertex::update() {
    for (int i = 0; i < subjects.size(); i++) {
        this->setInput(i, subjects[i]->getOutput());
    }
}

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

std::string Vertex::whoAmI() { return std::string("I am a Vertex!"); }
