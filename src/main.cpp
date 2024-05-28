#include <iostream>
#include <map>

#include "Input.h"
#include "Probe.h"
#include "Vertex.h"

void vertexObserverTest() {
    std::cout << "Start!" << std::endl;

    Input subject(1234);

    Vertex observer1;
    Vertex observer2;

    observer1.addSubject(&subject);

    observer2.addSubject(&observer1);
    observer2.addSubject(&subject);

    Probe probe;

    probe.addSubject(&observer1);

    std::cout << "setstate(1)" << std::endl;
    subject.setState(1);
    std::cout << "setstate(2)" << std::endl;
    subject.setState(2);
}

int main() { return 0; }
