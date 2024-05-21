#include <fstream>
class ResultToFile {
private: // Members
    std::fstream mOutputFile;

private: // Functions
    void openFile();
    void closeFile();
    void writeSing();

public:  // Functions
    ResultToFile(/* args */);
    ~ResultToFile();
};
