#include "FileToGraph.h"
#include "Vertex.h"
#include <fstream>

FileToGraph::FileToGraph(const std::string& aInputFile){
    this->mInputFile = aInputFile;
}

FileToGraph::~FileToGraph() {
    //delete mStrategy;
}

void FileToGraph::setStrategy(FileStrategy *aStrategy){
    this->mStrategy = aStrategy;
}

void FileToGraph::getGraph(std::map<std::string, std::string> &aVertexMap, std::map<std::string, std::string> &aEdgeMap) {
    mStrategy->openFile(mInputFile);

    // Read vertices and edges using strategy pattern
    mStrategy->readFile(aVertexMap, aEdgeMap);

    mStrategy->closeFile();
}
