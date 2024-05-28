#include "GraphBuilder.h"

#include "Circuit.h"

#include <map>
#include <string>

void GraphBuilder::createGraph(std::map<std::string,std::string> vertexNameType, std::multimap<std::string,std::string> vertexConnections) {
    populateCircuit(vertexNameType);
    connectVertices(vertexConnections);
}

void GraphBuilder::populateCircuit(std::map<std::string,std::string> vertexNameType) {
    std::map<std::string, Vertex> vertexMap = Circuit::getInstance().getVertexMap();
    vertexMap.clear();  // Remove all elements from the map
    
}

void GraphBuilder::connectVertices(std::multimap<std::string,std::string> vertexConnections) {

}