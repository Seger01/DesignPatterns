#include "Vertex.h"
#include <map>
#include <string>

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