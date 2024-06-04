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
}
