#pragma once

#include "Vertex.h"
#include <iostream>
#include <map>
#include <string>

class Circuit {
private:
    // Private constructor to prevent instantiation
    Circuit() {}

    static Circuit* mCircuit;

    std::map<std::string, Vertex*> mMapVertexes;

public:
    // Public destructor
    ~Circuit();
    // Delete copy constructor and assignment operator to prevent copying
    Circuit(const Circuit&) = delete;
    Circuit& operator=(const Circuit&) = delete;

    void runSim();

    // Static method to get the single instance of the class
    static Circuit& getInstance();

    std::map<std::string, Vertex*>& getVertexMap();
};
