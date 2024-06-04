#include <algorithm>
#include <iostream>

#include "Vertex.h"
#include "VertexFactory.h"

Vertex::Vertex() {}

Vertex::Vertex(std::string id) {
    Factory::VertexFactory<std::string, Vertex>::assign(id, this); // Associate the ID of the child, so the factory
                                                                   // knows which type of child to create
    std::cout << "Vertex assignment constructor" << std::endl;

    mInput = new int[1];
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
    } else {
        std::cout << "Vertex::subscribe called" << std::endl;
    }

    observers.push_back(observer);
    std::cout << "Vertex::subscribe called2" << std::endl;
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
    std::cout << "Vertex::addSubject() " << std::endl;
    std::cout << subject << std::endl;

    std::cout << "accesing subject" << std::endl;
    subject->whoAmI();
    std::cout << "push_back" << std::endl;
    subjects.push_back(subject);
    std::cout << "addSubject() " << subjects.size() << std::endl;
    subject->subscribe(this);
}

void Vertex::removeSubject(Vertex* subject) {
    subjects.erase(std::remove(subjects.begin(), subjects.end(), subject), subjects.end());
    subject->unsubscribe(this);
}
void Vertex::notify() {
    std::cout << "Vertex::notify()" << std::endl;
    for (Vertex* observer : observers) {
        observer->update();
    }
}

void Vertex::setState(int state) {
    this->state = state;
    notify();
}

void Vertex::setInput(int aIndex, int value) {
    std::cout << "Vertex::setInput, mAmountInputs: " << mAmountInputs << std::endl;
    // std::cout << "setInput " << aIndex << ", " << value << std::endl;
    // mOutput = value;
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
    std::cout << "Vertex::update()" << std::endl;
    for (int i = 0; i < subjects.size(); i++) {
        this->setInput(i, subjects[i]->getOutput());
    }
}

int Vertex::bumpAmountInputs() {
    if (mAmountInputs >= mMaxInputs) {
        std::cout << "Cannot increase amount of inputs for vertex, " << mAmountInputs << " already set!" << std::endl;
        return -1;
    }
    mAmountInputs++;
    return 0;
}

std::string Vertex::whoAmI() { return std::string("I am a Vertex!"); }

// #include "Vertex.h"
// #include "VertexFactory.h"
// #include <iostream>
//
// Vertex::Vertex() {
//     std::cout << "Vertex default constructor" << std::endl;
// }
//
// Vertex::Vertex(int id) {
//     Factory::VertexFactory<int,Vertex>::assign(id,this); // Associate the ID of the child, so the factory knows which
//     type of child to create std::cout << "Vertex assignment constructor" << std::endl;
// }
//
// Vertex::~Vertex() {
//     std::cout << "Vertex destructor" << std::endl;
// }
// >>>>>>> development
