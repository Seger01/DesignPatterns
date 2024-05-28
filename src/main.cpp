#include "Input.h"
#include "Probe.h"
#include "Vertex.h"
#include "VertexFactory.h"
#include <iostream>
#include <map>

// void vertexObserverTest() {
//     std::cout << "Start!" << std::endl;

//     Vertex* pInput = Factory::VertexFactory<int, Vertex>::create subject(1234);

//     Vertex observer1;
//     Vertex observer2;

//     observer1.addSubject(&subject);

//     observer2.addSubject(&observer1);
//     observer2.addSubject(&subject);

//     Probe probe;

//     probe.addSubject(&observer1);

//     std::cout << "setstate(1)" << std::endl;
//     subject.setState(1);
//     std::cout << "setstate(2)" << std::endl;
//     subject.setState(2);
// }

int main() {
    std::cout << std::endl << std::endl;
    Vertex* pVertex = Factory::VertexFactory<std::string, Vertex>::create("NOR");

    if (pVertex != nullptr) {
        pVertex->getOutput();
        delete pVertex;
    }
    std::cout << std::endl << std::endl;
    return 0;
}
