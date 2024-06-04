#include "FileToGraph.h"
#include "Vertex.h"
#include <cmath>
#include <fstream>

/**
 ************************************************************
 * @brief Constructor for FileToGraph
 *
 * Initializes the FileToGraph object with the input file.
 *
 * @param[in] aInputFile - The input file name
 */
FileToGraph::FileToGraph(const std::string& aInputFile) {
    this->mInputFile = aInputFile;
    this->mNumOfConfigs = -1;
    this->mStrategy = nullptr;
}

/**
 ************************************************************
 * @brief Destructor for FileToGraph
 *
 * Cleans up resources used by the FileToGraph object.
 */
FileToGraph::~FileToGraph() {
    if (mStrategy != nullptr)
    {
        delete mStrategy;
    }
}

/**
 ************************************************************
 * @brief Counts the number of configurations
 *
 * Counts the number of configurations based on the input vertices.
 *
 * @param[in] aMap - Map of vertex names to types
 */
void FileToGraph::countConfigs(const std::map<std::string, std::string>& aMap) {
    int counter = 0;

    for (const auto& pair : aMap) {
        if (pair.second == "INPUT") {
            ++counter;
        }
    }

    this->mNumOfConfigs = pow(2, counter);
}

/**
 ************************************************************
 * @brief Checks the connectivity of vertices
 *
 * Ensures that all vertices except probes are connected.
 *
 * @param[in] aVertexMap - Map of vertex names to types
 * @param[in] aEdgeMap - Multimap of edge connections
 */
void FileToGraph::checkVertexes(std::map<std::string, std::string>& aVertexMap,
                                std::multimap<std::string, std::string>& aEdgeMap) {

    std::map<std::string, std::string>::iterator iterator = aVertexMap.begin();

    for (iterator; iterator != aVertexMap.end(); iterator++) {
        std::string vertex;
        if (iterator->second == "PROBE") { // Probes should not be connected to anything
            continue;
        }
        vertex = iterator->first;

        if (aEdgeMap.find(vertex) == aEdgeMap.end()) {
            std::cerr << "vertex: " << vertex << " not connected" << std::endl;
            std::cerr << "Check the edges of the input file" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

/**
 ************************************************************
 * @brief Checks the validity of edges
 *
 * Ensures that all edges connect to valid vertices.
 *
 * @param[in] aVertexMap - Map of vertex names to types
 * @param[in] aEdgeMap - Multimap of edge connections
 */
void FileToGraph::checkEdges(std::map<std::string, std::string>& aVertexMap,
                             std::multimap<std::string, std::string>& aEdgeMap) {
    std::multimap<std::string, std::string>::iterator iterator = aEdgeMap.begin();

    for (iterator; iterator != aEdgeMap.end(); iterator++) {
        std::string edge1, edge2;
        edge1 = iterator->first;
        edge2 = iterator->second;

        if (aVertexMap.find(edge1) == aVertexMap.end()) {
            std::cerr << "Vertex: " << edge1 << " does not exist" << std::endl;
            std::cerr << "Check the edges of the input file" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (aVertexMap.find(edge2) == aVertexMap.end()) {
            std::cerr << "Vertex: " << edge2 << " does not exist" << std::endl;
            std::cerr << "Check the edges of the input file" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

/**
 ************************************************************
 * @brief Sets the strategy for reading the file
 *
 * Sets the file strategy to be used for reading the file.
 *
 * @param[in] aStrategy - Pointer to the FileStrategy object
 */
void FileToGraph::setStrategy(FileStrategy* aStrategy) { this->mStrategy = aStrategy; }

/**
 ************************************************************
 * @brief Gets the number of configurations
 *
 * Returns the number of configurations calculated.
 *
 * @return The number of configurations
 */
int FileToGraph::getNumOfConfigs() { return this->mNumOfConfigs; }

/**
 ************************************************************
 * @brief Builds the graph from the file
 *
 * Reads the vertices and edges from the file and checks their validity.
 *
 * @param[inout] aVertexMap - Map of vertex names to types
 * @param[inout] aEdgeMap - Multimap of edge connections
 */
void FileToGraph::getGraph(std::map<std::string, std::string>& aVertexMap,
                           std::multimap<std::string, std::string>& aEdgeMap) {
    if (this->mStrategy == nullptr) {
        std::cerr << "Strategy not set\n" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    mStrategy->openFile(mInputFile);

    // Read vertices and edges using strategy pattern
    mStrategy->readFile(aVertexMap, aEdgeMap);

    mStrategy->closeFile();

    countConfigs(aVertexMap);

    checkVertexes(aVertexMap, aEdgeMap);    

    checkEdges(aVertexMap, aEdgeMap);
}