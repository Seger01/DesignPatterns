/**
 ************************************************************
 * @file GraphBuilder.h
 *
 * This file contains the declaration of the GraphBuilder class, which is
 * responsible for creating and managing the graph structure of vertices and
 * their connections. It includes methods to populate the circuit with vertices,
 * connect them, and check for cycles in the graph.
 *
 */
#include "GraphBuilder.h"

#include "Circuit.h"
#include "Vertex.h"
#include "VertexFactory.h"

#include <list>
#include <map>
#include <string>

/**
 ************************************************************
 * @brief Creates the graph from the provided vertex information.
 *
 * This method populates the circuit with vertices and connects them according
 * to the specified connections. It also checks for cycles in the graph.
 *
 * @param[in] vertexNameType - Map containing vertex names and their corresponding types.
 * @param[in] vertexConnections - Multimap containing vertex connections (output to input).
 */
void GraphBuilder::createGraph(std::map<std::string, std::string>& vertexNameType,
                               std::multimap<std::string, std::string>& vertexConnections) {
    populateCircuit(vertexNameType);
    connectVertices(vertexConnections);
    std::map<std::string, Vertex*> vertexMap = Circuit::getInstance().getVertexMap();
    if (hasCycle(vertexMap, vertexConnections)) {
        std::cout << "Input file contains cycles, aborting" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

/**
 ************************************************************
 * @brief Populates the circuit with vertices.
 *
 * This method iterates through the provided map of vertex names and types,
 * and creates the corresponding vertices in the circuit.
 *
 * @param[in] vertexNameType - Map containing vertex names and their corresponding types.
 */
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
        std::string type = iter->second;
        if (type.find("INPUT") != std::string::npos) {
            type = "INPUT";
        }
        Vertex* pVertex = Factory::VertexFactory<std::string, Vertex>::create(type); // Create a new vertex of
                                                                                     // the right type
                                                                                     // (iter->second contains
                                                                                     // the type as a string)
        vertexMap.insert(std::make_pair(iter->first, pVertex));                      // Insert the new vertex pointer

        ++iter;
    }
}

/**
 ************************************************************
 * @brief Connects the vertices according to the provided connections.
 *
 * This method iterates through the provided multimap of vertex connections
 * and sets up the appropriate connections between the vertices in the circuit.
 *
 * @param[in] vertexConnections - Multimap containing vertex connections (output to input).
 */
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
}

/**
 ************************************************************
 * @brief Performs a DFS to detect cycles in the graph.
 *
 * This method recursively checks for cycles starting from the given node,
 * using Depth-First Search (DFS) and keeping track of visited nodes and the recursion stack.
 *
 * @param[in] node - The starting node for the DFS.
 * @param[inout] visited - Map indicating whether a node has been visited.
 * @param[inout] recStack - Map indicating whether a node is in the recursion stack.
 * @param[in] edges - Multimap containing the edges of the graph.
 *
 * @return True if a cycle is detected, otherwise false.
 */
bool GraphBuilder::hasCycleDFS(const std::string& node, std::map<std::string, bool>& visited,
                               std::map<std::string, bool>& recStack,
                               const std::multimap<std::string, std::string>& edges) {
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;

        auto range = edges.equal_range(node);
        for (auto i = range.first; i != range.second; ++i) {
            std::string neighbour = i->second;
            if (!visited[neighbour] && hasCycleDFS(neighbour, visited, recStack, edges))
                return true;
            else if (recStack[neighbour])
                return true;
        }
    }
    recStack[node] = false;
    return false;
}

/**
 ************************************************************
 * @brief Checks if the graph contains a cycle.
 *
 * This method uses DFS to detect cycles in the graph represented by the
 * provided vertices and edges.
 *
 * @param[in] vertices - Map containing the vertices of the graph.
 * @param[in] edges - Multimap containing the edges of the graph.
 *
 * @return True if a cycle is detected, otherwise false.
 */
bool GraphBuilder::hasCycle(const std::map<std::string, Vertex*>& vertices,
                            const std::multimap<std::string, std::string>& edges) {
    std::map<std::string, bool> visited;
    std::map<std::string, bool> recStack;

    for (auto& pair : vertices) {
        visited[pair.first] = false;
        recStack[pair.first] = false;
    }

    for (auto& pair : vertices) {
        if (hasCycleDFS(pair.first, visited, recStack, edges))
            return true;
    }

    return false;
}
