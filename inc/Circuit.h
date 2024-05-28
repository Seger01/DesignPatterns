#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Vertex.h"

class Circuit {
private:
    std::map<std::string, Vertex> mMapVertexes;

private:
    // Private constructor to prevent instantiation
    Circuit() { std::cout << "Circuit singleton instance created." << std::endl; }

    // Private destructor
    ~Circuit() { std::cout << "Circuit singleton instance destroyed." << std::endl; }

public:
    int state = 0;
    // Delete copy constructor and assignment operator to prevent copying
    Circuit(const Circuit&) = delete;
    Circuit& operator=(const Circuit&) = delete;

    // Static method to get the single instance of the class
    static Circuit& getInstance() {
        static Circuit instance;
        return instance;
    }

    // Example method
    void showMessage() { std::cout << "Circuit singleton instance method called." << state << std::endl; }
};
