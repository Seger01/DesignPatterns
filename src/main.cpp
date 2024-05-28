#include "Circuit.h"
#include "GraphBuilder.h"
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
    
    std::multimap<std::string,std::string> myConnections;
    std::map<std::string,std::string> myVertices;
    myVertices.insert({"andSiem","AND"});
    myVertices.insert({"orSeger","OR"});
    myVertices.insert({"inputSean","INPUT"});
    GraphBuilder builder;
    builder.createGraph(myVertices, myConnections);

    std::map<std::string, Vertex*> vertexMap = Circuit::getInstance().getVertexMap();
    std::map<std::string, Vertex*>::iterator it = vertexMap.begin();
    while (it != vertexMap.end()) {
        std::cout << "My name is " << it->first << ". " << it->second->whoAmI() << std::endl;
        ++it;
    }

    std::cout << std::endl << std::endl;
    return 0;
}
