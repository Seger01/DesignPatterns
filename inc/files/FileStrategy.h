/**
 ************************************************************
 * @file FileStrategy.h
 *
 * Defines the FileStrategy abstract base class for file reading
 * strategies.
 *
 * @autor Sean Groenenboom
 * @date June 4, 2024
 */

#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H

#include <map>
#include <string>

/**
 ************************************************************
 * @class FileStrategy
 *
 * Abstract base class for file reading strategies.
 */
class FileStrategy {
public:
    virtual ~FileStrategy() {}

    virtual void openFile(const std::string& aFilename) = 0;
    virtual void closeFile() = 0;
    virtual void readFile(std::map<std::string, std::string>& aVertexMap, std::multimap<std::string, std::string>& aEdgeMap) = 0;
};

#endif // FILESTRATEGY_H
