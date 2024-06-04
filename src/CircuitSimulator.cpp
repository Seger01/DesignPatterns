#include "CircuitSimulator.h"
#include "Circuit.h"
#include "GraphBuilder.h"
#include "ResultToFile.h"
#include "TextStrategy.h"

CircuitSimulator::CircuitSimulator() {
    mFileToGraph = new FileToGraph("inputfile_fulladder.txt");
    mResultToFile = new ResultToFile();
    mCircuitInitializer = new CircuitInitializer();
}
CircuitSimulator::~CircuitSimulator() {
    delete mCircuitInitializer;
    delete mResultToFile;
    delete mFileToGraph;
}

void CircuitSimulator::run() {
    std::cout << "CircuitSimulator::run()" << std::endl;
    TextStrategy textStrategy;
    GraphBuilder graphBuilder;

    Circuit& circuit = Circuit::getInstance();

    std::map<std::string, std::string> vertexMap;
    std::multimap<std::string, std::string> edgeMap;
    int numberOfConfigs = 0;

    mFileToGraph->setStrategy(&textStrategy);
    mFileToGraph->getGraph(vertexMap, edgeMap);
    numberOfConfigs = mFileToGraph->getNumOfConfigs();

    for (const auto& pair : vertexMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    // Temp shit
    // Map with vertices
    // std::map<std::string, std::string> myVertices;

    // myVertices.insert({"andSiem", "AND"});
    // myVertices.insert({"orSeger", "OR"});
    // myVertices.insert({"inputSean", "INPUT"});
    // myVertices.insert({"inputWouter", "INPUT"});
    // myVertices.insert({"inputLoek", "INPUT"});

    // Map with connections
    // std::multimap<std::string, std::string> myConnections;
    // myConnections.insert({"inputSean", "andSiem"});
    // myConnections.insert({"inputWouter", "andSiem"});
    // myConnections.insert({"andSiem", "orSeger"});
    // myConnections.insert({"inputLoek", "orSeger"});
    // graphBuilder.createGraph(myVertices,myConnections);
    // End temp shit

    graphBuilder.createGraph(vertexMap, edgeMap);

    std::cout << "Number of configs: " << numberOfConfigs << std::endl;

    // mCircuitInitializer->initCircuit(std::map<std::string, Vertex *> &aCircuit)
    for (int i = 0; i < numberOfConfigs; i++) {
        mCircuitInitializer->initCircuit();

        circuit.runSim();

        mResultToFile->writeOutput();
    }

    return;
}
