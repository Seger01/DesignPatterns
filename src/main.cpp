#include "Circuit.h"
#include "GraphBuilder.h"
#include "Input.h"
#include "Probe.h"
#include "Vertex.h"
#include "VertexFactory.h"
#include <iostream>
#include <map>
#include "FileToGraph.h"
#include "TextStrategy.h"
#include "ResultToFile.h"

void GraphBuilderTest() {
    // Map with vertices
    std::map<std::string,std::string> myVertices;
    myVertices.insert({"andSiem","AND"});
    myVertices.insert({"orSeger","OR"});
    myVertices.insert({"inputSean","INPUT"});
    myVertices.insert({"inputWouter","INPUT"});
    myVertices.insert({"inputLoek","INPUT"});

    // Map with connections
    std::multimap<std::string,std::string> myConnections;
    myConnections.insert({"inputSean","andSiem"});
    myConnections.insert({"inputWouter","andSiem"});
    myConnections.insert({"andSiem","orSeger"});
    myConnections.insert({"inputLoek","orSeger"});

    GraphBuilder builder;
    builder.createGraph(myVertices, myConnections);

    std::map<std::string, Vertex*> vertexMap = Circuit::getInstance().getVertexMap();
    std::map<std::string, Vertex*>::iterator it = vertexMap.begin();
    while (it != vertexMap.end()) {
        std::cout << "My name is " << it->first << ". " << it->second->whoAmI() << std::endl;
        //std::cout << "My output is connected to: ";
        
        ++it;
    }
}

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

void fileTest(){
    std::map<std::string,std::string> vertexMap;
    std::multimap<std::string,std::string> edgeMap;
    std::map<std::string, Vertex> circuitMap;
    FileToGraph fileReader("./inputfile.txt");
    TextStrategy strategy;
    ResultToFile fileWriter;

    fileReader.setStrategy(&strategy);
    fileReader.getGraph(vertexMap,edgeMap);

    for(std::multimap<std::string,std::string>::iterator iterator = edgeMap.begin(); iterator != edgeMap.end(); iterator++){
        std::cout << iterator->first << ", " << iterator->second << std::endl;
    }
    fileWriter.writeOutput(circuitMap);

}

int main() {
    std::cout << std::endl << std::endl;

    //GraphBuilderTest();
    fileTest();

    std::cout << std::endl << std::endl;
    return 0;
}
