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
    int mNumOfConfigs;

public:// constructor
    FileToGraph(const std::string& aInputFile);
    ~FileToGraph();

    private: //private functions
    void countConfigs(const std::map<std::string, std::string>& aMap);

    public: //public functions

    int getNumOfConfigs();

    void setStrategy(FileStrategy *aStrategy);
    void getGraph(std::map<std::string, std::string>& aVertexMap, std::multimap<std::string, std::string>& aEdgeMap);
};

#endif // FILETOGRAPH_H
