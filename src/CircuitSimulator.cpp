#include "CircuitSimulator.h"
#include "Circuit.h"
#include "GraphBuilder.h"
#include "ResultToFile.h"
#include "TextStrategy.h"

/**
 ************************************************************
 * @brief Constructor for the CircuitSimulator class
 *
 * Initializes the CircuitSimulator with the given file path.
 * Sets up the FileToGraph, ResultToFile, and CircuitInitializer components.
 *
 * @param[in] aFilepath - Path to the file used for simulation
 */
CircuitSimulator::CircuitSimulator(std::string aFilepath) {
    mFileToGraph = new FileToGraph(aFilepath);
    mResultToFile = new ResultToFile();
    mCircuitInitializer = new CircuitInitializer();
}

/**
 ************************************************************
 * @brief Destructor for the CircuitSimulator class
 *
 * Deletes the dynamically allocated components to free allocated memory
 *
 */
CircuitSimulator::~CircuitSimulator() {
    delete mCircuitInitializer;
    delete mResultToFile;
    delete mFileToGraph;
}

/**
 ************************************************************
 * @brief Runs the circuit simulation
 *
 * Sets up the graph from the file, initializes the circuit,
 * runs the simulation, and writes the output to a file
 *
 */
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

    // Initialize and simulate the circuit for each configuration
    for (int i = 0; i < numberOfConfigs; i++) {
        mCircuitInitializer->initCircuit(vertexMap);

        circuit.runSim();

        mResultToFile->writeOutput();
    }

    // Delete the singleton instance of Circuit
    delete &Circuit::getInstance();

    return;
}
