/**
 ************************************************************
 * @file FileToGraph.h
 *
 * Defines the FileToGraph class for reading a file and constructing
 * a graph representation of a circuit.
 *
 * @autor Sean Groenenboom
 * @date June 4, 2024
 */
#ifndef FILETOGRAPH_H
#define FILETOGRAPH_H

#include <map>
#include <string>

#include "FileStrategy.h"
#include "Vertex.h"

/**
 ************************************************************
 * @class FileToGraph
 *
 * Reads a file and constructs a graph representation of the circuit.
 */
class FileToGraph {
private:
    std::string mInputFile;
    FileStrategy* mStrategy;
    int mNumOfConfigs;

public: // constructor
    FileToGraph(const std::string& aInputFile);
    ~FileToGraph();

private: // private functions
    void countConfigs(const std::map<std::string, std::string>& aMap);
    void checkVertexes(std::map<std::string, std::string>& aVertexMap, std::multimap<std::string, std::string>& aEdgeMap);
    void checkEdges(std::map<std::string, std::string>& aVertexMap, std::multimap<std::string, std::string>& aEdgeMap);

public: // public functions
    int getNumOfConfigs();

    void setStrategy(FileStrategy* aStrategy);
    void getGraph(std::map<std::string, std::string>& aVertexMap, std::multimap<std::string, std::string>& aEdgeMap);
};

#endif // FILETOGRAPH_H
