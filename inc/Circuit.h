#pragma once

#include <iostream>
#include <map>
#include <string>

class Vertex;

class Circuit {
private:
    // Private constructor to prevent instantiation
    Circuit() { std::cout << "Circuit singleton instance created." << std::endl; }

    static Circuit* mCircuit;

    std::map<std::string, Vertex*> mMapVertexes;

public:
    // Public destructor
    ~Circuit() { std::cout << "Circuit singleton instance destroyed." << std::endl; }
    // Delete copy constructor and assignment operator to prevent copying
    Circuit(const Circuit&) = delete;
    Circuit& operator=(const Circuit&) = delete;

    // Static method to get the single instance of the class
    static Circuit* getInstance();

    std::map<std::string, Vertex*> getVertexMap();
};
