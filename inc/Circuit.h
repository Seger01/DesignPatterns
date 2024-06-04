/**
 ************************************************************
 * @file Circuit.h
 *
 * Manages the components and operations of a circuit simulation.
 *
 * This file defines the Circuit class, which represents a circuit
 * in a simulation. It provides methods for initializing the circuit,
 * running simulations, and accessing vertex information.
 *
 * @author Seger01
 * @date 04/06/2024
 */
#pragma once

#include "Vertex.h"
#include <iostream>
#include <map>
#include <string>
/**
 ************************************************************
 * @class Circuit
 *
 * @brief Manages a collection of Vertex objects and runs simulations on them.
 *
 * The Circuit class is a singleton that contains a map of Vertex objects
 * identified by their string keys. It provides methods to run simulations
 * and to access the map of Vertex objects.
 *
 * @note The class prevents copying and assignment by deleting the copy
 * constructor and assignment operator.
 *
 * @author Seger01
 * @date 04/06/2024
 */
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
