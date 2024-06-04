#ifndef RESULT_TO_FILE_H
#define RESULT_TO_FILE_H

#include <fstream>

#define OUTPUTDIR "output"


/**
 ************************************************************
 * @class ResultToFile
 *
 * Manages writing the results of circuit operations to a file.
 *
 * @author Sean Groenenboom
 * @date June 4, 2024
 */
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

    void writeOutput();
};

#endif // RESULT_TO_FILE_H
