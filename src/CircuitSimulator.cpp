#include "CircuitSimulator.h"
#include "Circuit.h"
#include "GraphBuilder.h"
#include "ResultToFile.h"
#include "TextStrategy.h"

CircuitSimulator::CircuitSimulator(std::string aFilepath) {
    mFileToGraph = new FileToGraph(aFilepath);
    mResultToFile = new ResultToFile();
    mCircuitInitializer = new CircuitInitializer();
}
CircuitSimulator::~CircuitSimulator() {
    delete mCircuitInitializer;
    delete mResultToFile;
    delete mFileToGraph;
}

void CircuitSimulator::run() {
    TextStrategy textStrategy;
    GraphBuilder graphBuilder;

    Circuit& circuit = Circuit::getInstance();

    std::map<std::string, std::string> vertexMap;
    std::multimap<std::string, std::string> edgeMap;
    int numberOfConfigs = 0;

    mFileToGraph->setStrategy(&textStrategy);
    mFileToGraph->getGraph(vertexMap, edgeMap);
    numberOfConfigs = mFileToGraph->getNumOfConfigs();

    graphBuilder.createGraph(vertexMap, edgeMap);

    std::cout << "Number of configs: " << numberOfConfigs << std::endl;

    // mCircuitInitializer->initCircuit(std::map<std::string, Vertex *> &aCircuit)
    for (int i = 0; i < numberOfConfigs; i++) {
        mCircuitInitializer->initCircuit();

        circuit.runSim();

        mResultToFile->writeOutput();
    }

    delete &Circuit::getInstance();


    return;
}
