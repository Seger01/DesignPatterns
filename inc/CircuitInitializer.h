#ifndef CIRCUITINITIALIZER_H
#define CIRCUITINITIALIZER_H

#include <map>
#include <vector>
#include <string>

class Vertex;

/**
 ************************************************************
 * @class CircuitInitializer
 *
 * Initializes and manages the state of the circuit inputs and iteration.
 *
 * @author Sean Groenenboom
 * @date June 4, 2024
 */
class CircuitInitializer {
private: // members
    int mIteration;
    std::vector<Vertex*> mInputs;

public: // constructor
    CircuitInitializer(/* args */);
    ~CircuitInitializer();

private: // private funtions
    void fillInputs(std::map<std::string, std::string>& aVertexMap);
    void setInputs();

public: // public functions
    void initCircuit(std::map<std::string, std::string>& aVertexMap);
};

#endif // CIRCUITINITIALIZER_H
