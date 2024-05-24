#ifndef FILETOGRAPH_H
#define FILETOGRAPH_H

#include <map>
#include <string>

#include "FileStrategy.h"
#include "Vertex.h"

class FileToGraph {
private:
    std::string mInputFile;
    FileStrategy* mStrategy;

public:
    FileToGraph(const std::string& aInputFile);
    ~FileToGraph();

    void setStrategy(FileStrategy *aStrategy);
    void getGraph(std::map<std::string, std::string>& aVertexMap, std::map<std::string, std::string>& aEdgeMap);
};

#endif // FILETOGRAPH_H
