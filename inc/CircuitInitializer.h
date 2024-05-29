#ifndef CIRCUITINITIALIZER_H
#define CIRCUITINITIALIZER_H

#include <vector>

class Vertex;
class CircuitInitializer {
private: // members
    int mIteration;
    std::vector<Vertex *> mInputs;

public: // constructor
    CircuitInitializer(/* args */);
    ~CircuitInitializer();

private: // private funtions
    void fillInputs();
    void setInputs();
public:  // public functions
    void initCircuit();
};

#endif // CIRCUITINITIALIZER_H
