#ifndef CIRCUITINITIALIZER_H
#define CIRCUITINITIALIZER_H

#include <map>
#include <string>
#include <vector>

class Vertex;
class Input;
class CircuitInitializer {
private: // members
    int mIteration;
    std::vector<Input*> mInputs;

public: // constructor
    CircuitInitializer(/* args */);
    ~CircuitInitializer();

private: // private funtions
    void fillInputs(std::map<std::string, Vertex*>& aCircuit);
    void setInputs();
public:  // public functions
    void initCircuit(std::map<std::string, Vertex*>& aCircuit);
};

#endif // CIRCUITINITIALIZER_H
