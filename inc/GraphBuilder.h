#include <map>
#include <string>

class GraphBuilder {
public:
    void createGraph(std::map<std::string,std::string> &vertexNameType, std::multimap<std::string,std::string> &vertexConnections);
private:
    void populateCircuit(std::map<std::string,std::string> &vertexNameType);
    void connectVertices(std::multimap<std::string,std::string> &vertexConnections);
};