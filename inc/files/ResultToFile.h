#ifndef RESULT_TO_FILE_H
#define RESULT_TO_FILE_H

#include <fstream>
#include <map>
#include <string>
#include "Vertex.h"
//class Vertex;

#define OUTPUTDIR "output"

class ResultToFile {
private: // Members
    std::fstream mOutputFile;
    std::string mFilename;
    bool mFileIsOpen;

private: // Functions
    void generateFile();
    void openFile();
    void closeFile();

public:  // Functions
    ResultToFile();
    ~ResultToFile();

    void writeOutput(const std::map<std::string, Vertex> &aData);
};

#endif // RESULT_TO_FILE_H
