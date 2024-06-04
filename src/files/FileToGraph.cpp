#include "FileToGraph.h"
#include "Vertex.h"
#include <cmath>
#include <fstream>

FileToGraph::FileToGraph(const std::string& aInputFile) {
    this->mInputFile = aInputFile;
    this->mNumOfConfigs = -1;
    this->mStrategy = nullptr;
}

FileToGraph::~FileToGraph() {
    // delete mStrategy;
}

void FileToGraph::countConfigs(const std::map<std::string, std::string>& aMap) {
    int counter = 0;

    for (const auto& pair : aMap) {
        if (pair.second == "INPUT") {
            ++counter;
        }
    }

    this->mNumOfConfigs = pow(2, counter);
}

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

void FileToGraph::setStrategy(FileStrategy* aStrategy) { this->mStrategy = aStrategy; }

int FileToGraph::getNumOfConfigs() { return this->mNumOfConfigs; }

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
