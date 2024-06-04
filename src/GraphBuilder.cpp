#include "GraphBuilder.h"

#include "Circuit.h"
#include "VertexFactory.h"

#include <map>
#include <string>

void GraphBuilder::createGraph(std::map<std::string, std::string>& vertexNameType,
                               std::multimap<std::string, std::string>& vertexConnections) {
    populateCircuit(vertexNameType);
    connectVertices(vertexConnections);
}

void GraphBuilder::populateCircuit(std::map<std::string, std::string>& vertexNameType) {
    std::map<std::string, Vertex*>& vertexMap = Circuit::getInstance().getVertexMap(); // Retrieve the map (containing
                                                                                       // vertex name and vertex
                                                                                       // pointer) from the Circuit
                                                                                       // singleton
    vertexMap.clear();                                                          // Remove all elements from the map
    std::map<std::string, std::string>::iterator iter = vertexNameType.begin(); // Create an iterator at the start of
                                                                                // the map (containing vertex name and
                                                                                // vertex type)
    while (iter != vertexNameType.end()) { // Iterate through the map (containing vertex name and vertex type)
        Vertex* pVertex = Factory::VertexFactory<std::string, Vertex>::create(iter->second); // Create a new vertex of
                                                                                             // the right type
                                                                                             // (iter->second contains
                                                                                             // the type as a string)
        vertexMap.insert(std::make_pair(iter->first, pVertex)); // Insert the new vertex pointer

        ++iter;
    }
}

void GraphBuilder::connectVertices(std::multimap<std::string, std::string>& vertexConnections) {
    std::map<std::string, Vertex*>& vertexMap = Circuit::getInstance().getVertexMap(); // Retrieve the map (containing
                                                                                       // vertex name and vertex
                                                                                       // pointer) from the Circuit
                                                                                       // singleton

    std::multimap<std::string, std::string>::iterator iter = vertexConnections.begin(); // Create an iterator at the
                                                                                        // start of the map (containing
                                                                                        // vertex names of output and
                                                                                        // input)
    while (iter != vertexConnections.end()) { // Iterate through the map (containing vertex names of output and input)
        std::cout << "start of while loop" << std::endl;
        Vertex* pVertexOutputting = vertexMap.find(iter->first)->second; // Get pointer to the first vertex in the map,
                                                                         // from which the output should be connected
        Vertex* pVertexReceiving = vertexMap.find(iter->second)->second;

        pVertexReceiving->addSubject(pVertexOutputting);
        // pVertex->subscribe(vertexMap.find(iter->second)->second); // Connect to output of the first vertex to the
        // input of the second vertex in the map
        if (pVertexReceiving->bumpAmountInputs() != 0) {
            std::cout << "Failed to increment inputs on " << iter->second << std::endl;
        }
        ++iter;
        // pVertexReceiving->setAmountInputs(pVertexReceiving->subjects.size()); // dirty but not my code :)
    }

    { // idk what this is I am tired

        std::multimap<std::string, std::string>::iterator iter = vertexConnections.begin(); // Create an iterator at the
                                                                                            // start of the map
                                                                                            // (containing vertex names
                                                                                            // of output and input)
        while (iter != vertexConnections.end()) { // Iterate through the map (containing vertex names of output and
                                                  // input)
            Vertex* pVertexOutputting = vertexMap.find(iter->first)->second; // Get pointer to the first vertex in the
                                                                             // map, from which the output should be
                                                                             // connected
            Vertex* pVertexReceiving = vertexMap.find(iter->second)->second;

            // pVertexReceiving->addSubject(pVertexOutputting);
            // // pVertex->subscribe(vertexMap.find(iter->second)->second); // Connect to output of the first vertex to
            // the
            // // input of the second vertex in the map
            //
            ++iter;

            pVertexReceiving->setAmountInputs(pVertexReceiving->subjects.size()); // dirty but not my code :)
        }
    }
}
