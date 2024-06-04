#include "Circuit.h"
#include "FileToGraph.h"
#include "GraphBuilder.h"
#include "Input.h"
#include "Probe.h"
#include "ResultToFile.h"
#include "TextStrategy.h"
#include "Vertex.h"
#include "VertexFactory.h"
#include <iostream>
#include <map>

#include "CircuitSimulator.h"

void GraphBuilderTest() {
    // Map with vertices
    std::map<std::string, std::string> myVertices;
    myVertices.insert({"andSiem", "AND"});
    myVertices.insert({"orSeger", "OR"});
    myVertices.insert({"inputSean", "INPUT"});
    myVertices.insert({"inputWouter", "INPUT"});
    myVertices.insert({"inputLoek", "INPUT"});

    // Map with connections
    std::multimap<std::string, std::string> myConnections;
    myConnections.insert({"inputSean", "andSiem"});
    myConnections.insert({"inputWouter", "andSiem"});
    myConnections.insert({"andSiem", "orSeger"});
    myConnections.insert({"inputLoek", "orSeger"});

    GraphBuilder builder;
    builder.createGraph(myVertices, myConnections);

    std::map<std::string, Vertex*> vertexMap = Circuit::getInstance().getVertexMap();
    std::map<std::string, Vertex*>::iterator it = vertexMap.begin();
    while (it != vertexMap.end()) {
        std::cout << "My name is " << it->first << ". " << it->second->whoAmI() << std::endl;
        // std::cout << "My output is connected to: ";

        ++it;
    }
}

void vertexObserverTest() {
    // std::cout << "Start!" << std::endl;
    //
    // // Vertex* pInput = Input
    // Vertex* pInput1 = Factory::VertexFactory<std::string, Vertex>::create("INPUT"); // Create a new vertex of
    //
    // Vertex* pProbe = Factory::VertexFactory<std::string, Vertex>::create("PROBE"); // Create a new vertex of
    //
    // pProbe->addSubject(pInput1);
    //
    // std::cout << "setstate(1)" << std::endl;
    // pInput1->setInput(0, 1);
    // std::cout << "Input output: " << pInput1->getOutput() << std::endl;
    // std::cout << "Probe output: " << pProbe->getOutput() << std::endl;
    // pInput1->setInput(0, 0);
    // std::cout << "Input output: " << pInput1->getOutput() << std::endl;
    // std::cout << "Probe output: " << pProbe->getOutput() << std::endl;
    std::cout << "Start!" << std::endl;

    // Vertex* pInput = Input
    Vertex* pInput1 = Factory::VertexFactory<std::string, Vertex>::create("INPUT"); // Create a new vertex of
    Vertex* pInput2 = Factory::VertexFactory<std::string, Vertex>::create("INPUT"); // Create a new vertex of

    Vertex* pAndGate = Factory::VertexFactory<std::string, Vertex>::create("AND"); // Create a new vertex of;
    pAndGate->setAmountInputs(2);

    pAndGate->addSubject(pInput1);
    pAndGate->addSubject(pInput2);

    Vertex* pProbe = Factory::VertexFactory<std::string, Vertex>::create("PROBE"); // Create a new vertex of

    pProbe->addSubject(pAndGate);

    std::cout << "setstate(1)" << std::endl;
    pInput1->setInput(0, 1);
    pInput2->setInput(0, 1);

    // std::cout << "Input output: " << pInput->getOutput() << std::endl;
    // std::cout << "Vertex output: " << observer1.getOutput() << std::endl;
    std::cout << "Probe output: " << pProbe->getOutput() << std::endl;
    std::cout << "setstate(2)" << std::endl;
    pInput1->setInput(0, 0);
    pInput2->setInput(0, 0);
    // std::cout << "Input output: " << pInput->getOutput() << std::endl;
    std::cout << "Probe output: " << pProbe->getOutput() << std::endl;
}

void fileTest() {
    std::map<std::string, std::string> vertexMap;
    std::multimap<std::string, std::string> edgeMap;
    FileToGraph fileReader("./inputfile.txt");
    TextStrategy strategy;
    ResultToFile fileWriter;

    fileReader.setStrategy(&strategy);
    fileReader.getGraph(vertexMap, edgeMap);

    for (std::multimap<std::string, std::string>::iterator iterator = edgeMap.begin(); iterator != edgeMap.end();
         iterator++) {
        std::cout << iterator->first << ", " << iterator->second << std::endl;
    }
    fileWriter.writeOutput();
}

int main() {
    // std::cout << std::endl << std::endl;
    //
    // GraphBuilderTest();
    //
    // std::cout << std::endl << std::endl;

    // vertexObserverTest();

    // GraphBuilderTest();
    //  fileTest();

    // if(Circuit::getInstance() != nullptr){
    //     delete Circuit::getInstance();
    // }
    CircuitSimulator circuitSimulator;

    circuitSimulator.run();
    return 0;
}
