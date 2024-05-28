#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H

#include <map>
#include <string>

class FileStrategy {
public:
    virtual ~FileStrategy() {}

    virtual void openFile(const std::string& aFilename) = 0;
    virtual void closeFile() = 0;
    virtual void readFile(std::map<std::string, std::string>& aVertexMap, std::map<std::string, std::string>& aEdgeMap) = 0;
};

#endif // FILESTRATEGY_H
