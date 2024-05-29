#include <iostream>
#include <string>

#include "CircuitInitializer.h"
#include "FileToGraph.h"
#include "ResultToFile.h"

class CircuitSimulator {
private:
    FileToGraph* mFileToGraph;
    ResultToFile* mResultToFile;
    CircuitInitializer* mCircuitInitializer;

public:
    CircuitSimulator();
    ~CircuitSimulator();

    void run();
};
