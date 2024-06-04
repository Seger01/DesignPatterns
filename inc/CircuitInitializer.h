#ifndef CIRCUITINITIALIZER_H
#define CIRCUITINITIALIZER_H

#include <map>
#include <vector>
#include <string>

class Vertex;
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
