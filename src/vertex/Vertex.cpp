#include <algorithm>
#include <iostream>

#include "Vertex.h"

Vertex::Vertex() {}

Vertex::~Vertex() {
    if (subjects.size() != 0) {
        for (Vertex* subject : subjects) {
            subject->unsubscribe(this);
        }
    }
}

void Vertex::subscribe(Vertex* observer) { observers.push_back(observer); }

void Vertex::unsubscribe(Vertex* observer) {
    if (observers.size() == 0) {
        return;
    }
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
void Vertex::addSubject(Vertex* subject) {
    subjects.push_back(subject);
    std::cout << "addSubject() " << subjects.size() << std::endl;
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

void Vertex::setInput(int aIndex, int value) { std::cout << "setInput " << aIndex << ", " << value << std::endl; }

int Vertex::getOutput() { return state; }

void Vertex::update() {
    for (int i = 0; i < subjects.size(); i++) {
        this->setInput(i, subjects[i]->getOutput());
    }
}
