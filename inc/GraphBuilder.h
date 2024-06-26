/**
 ************************************************************
 * @file GraphBuilder.h
 *
 * This file contains the definition of the GraphBuilder class, which is
 * responsible for creating and managing the graph structure of vertices and
 * their connections. It includes methods to populate the circuit with vertices,
 * connect them, and check for cycles in the graph.
 *
 */
#include "Vertex.h"
#include <map>
#include <string>

/**
 ************************************************************
 * @class GraphBuilder
 *
 * @brief Responsible for creating the vertices, subscribing them to each other and checking for loops
 *
 * The GraphBuilder class is responsible for creating and managing the graph
 * structure of vertices and their connections. It handles the population of
 * vertices in the circuit, connects them, and checks for cycles in the graph.
 *
 * Methods:
 * - createGraph: Creates the graph from the provided vertex information.
 * - populateCircuit: Populates the circuit with vertices.
 * - connectVertices: Connects the vertices according to the provided connections.
 * - hasCycleDFS: Performs a DFS to detect cycles in the graph.
 * - hasCycle: Checks if the graph contains a cycle.
 *
 */
class GraphBuilder {
public:
    void createGraph(std::map<std::string, std::string>& vertexNameType,
                     std::multimap<std::string, std::string>& vertexConnections);

private:
    void populateCircuit(std::map<std::string, std::string>& vertexNameType);
    void connectVertices(std::multimap<std::string, std::string>& vertexConnections);
    bool hasCycleDFS(const std::string& node, std::map<std::string, bool>& visited,
                     std::map<std::string, bool>& recStack, const std::multimap<std::string, std::string>& edges);
    bool hasCycle(const std::map<std::string, Vertex*>& vertices, const std::multimap<std::string, std::string>& edges);
};