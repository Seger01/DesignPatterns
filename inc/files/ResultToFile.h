#ifndef RESULT_TO_FILE_H
#define RESULT_TO_FILE_H

#include <fstream>

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

    void writeOutput();
};

#endif // RESULT_TO_FILE_H
