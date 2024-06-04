#ifndef TEXTSTRATEGY_H
#define TEXTSTRATEGY_H

#include "FileStrategy.h"

#include <fstream>
#include <iostream>
#include <set>

class TextStrategy : public FileStrategy {
private:
    std::ifstream mInputFile;
    std::set<std::string> stringSet = {"INPUT", "INPUT_HIGH", "INPUT_LOW", "PROBE", "AND",
                                       "NAND",  "OR",         "NOR",       "NOT",   "XOR"};

private:
    std::string removeAllSpaces(const std::string& aString);

public:
    TextStrategy();
    ~TextStrategy();

    void openFile(const std::string& aFilename) override;
    void closeFile() override;
    void readFile(std::map<std::string, std::string>& aVertexMap,
                  std::multimap<std::string, std::string>& aEdgeMap) override;
};

#endif // TEXTSTRATEGY_H
