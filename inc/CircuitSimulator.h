#include <iostream>
#include <string>

#include "CircuitInitializer.h"
#include "FileToGraph.h"
#include "ResultToFile.h"

/**
 ************************************************************
 * @class CircuitSimulator
 *
 * @brief Manages the simulation of a circuit based on an input file.
 *
 * The CircuitSimulator class initializes the circuit, runs the simulation,
 * and outputs the results to a file. It uses various components such as
 * FileToGraph, CircuitInitializer, and ResultToFile to achieve this.
 *
 * @author Seger01
 * @date 04/06/2024
 */
class CircuitSimulator {
private:
    FileToGraph* mFileToGraph;
    ResultToFile* mResultToFile;
    CircuitInitializer* mCircuitInitializer;

public:
    CircuitSimulator(std::string aFilepath);
    ~CircuitSimulator();

    void run();
};
