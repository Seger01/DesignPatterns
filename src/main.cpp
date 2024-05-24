#include "FileToGraph.h"
#include "ResultToFile.h"
#include "TextStrategy.h"
#include "Vertex.h"
#include <iostream>
#include <map>

int main() {
    std::map<std::string, Vertex> data;
    std::map<std::string, std::string> vertex, edge;
    ResultToFile writer;
    TextStrategy strategy;
    FileToGraph reader("inputfile.txt");
    // writer.writeOutput(data);
    // writer.writeOutput(data);

    reader.setStrategy(&strategy);
    reader.getGraph(vertex, edge);

    // Iterating through the map using a for loop
    std::cout << "Vertex" << std::endl;
    for (auto it = vertex.begin(); it != vertex.end(); ++it) {
        std::cout << it->first << ", " << it->second << std::endl;
    }

    std::cout << "Edge" << std::endl;
    // Iterating through the map using a for loop
    for (auto it = edge.begin(); it != edge.end(); ++it) {
        std::cout << it->first << ", " << it->second << std::endl;
    }

    return 0;
}
