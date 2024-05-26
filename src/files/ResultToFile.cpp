#include "ResultToFile.h"

#include "Vertex.h" 
#include "Input.h"
#include "Probe.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <filesystem>

ResultToFile::ResultToFile() {
    mFileIsOpen = false;
    generateFile();
}

ResultToFile::~ResultToFile() {
    if (mFileIsOpen) {
        closeFile();
    }
}

void ResultToFile::generateFile() {
        // Ensure the output directory exists
    std::string outputDir = OUTPUTDIR;
    if (!std::filesystem::exists(outputDir)) {
        std::filesystem::create_directory(outputDir);
    }

    std::ostringstream oss;
    std::time_t now = std::time(nullptr);
    oss << outputDir << "/circuitOutput_" << std::put_time(std::localtime(&now), "%Y_%m_%d_%H:%M:%S") << ".txt";
    mFilename = oss.str();
}

void ResultToFile::openFile() {
    if (!mFileIsOpen) {
        // Open file in append mode
        mOutputFile.open(mFilename, std::ios::out | std::ios::app);
        
        // Check if the file was opened successfully
        if (!mOutputFile.is_open()) {
            std::cerr << "Failed to open the file." << std::endl;
            return;
        }

        // Set mIsFileOpen to true
        mFileIsOpen = true;
    }
}

void ResultToFile::closeFile() {
    if (mFileIsOpen) {
        mOutputFile.close();
        mFileIsOpen = false;
    }
}

void ResultToFile::writeOutput(const std::map<std::string, Vertex> &aData) {
    openFile(); // Ensure the file is open before writing

    if (!mOutputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    static int simCount = 1;
    mOutputFile << "-------------------------------------------------" << "\n";
    mOutputFile << "Sim " << simCount++ << "\n";

    // Input values
    mOutputFile << "Input:" << "\n";
    for (auto pair = aData.begin(); pair != aData.end(); ++pair) {
        //Use dynamic_cast to check if the Vertex is an instance of Input
        Input* inputPtr = dynamic_cast<Input*>(pair.second);
        if (inputPtr) {
            mOutputFile << pair->first << ": \t";
            mOutputFile << pair->second.getInput() << "\n";
        }
    }

    // Output values
    mOutputFile << "\n"<< "Output:" << "\n";
    for (auto pair = aData.begin(); pair != aData.end(); ++pair) {
        //Use dynamic_cast to check if the Vertex is an instance of Input
        Probe* probePtr = dynamic_cast<Probe*>(pair.second);
        if (probePtr) {
            mOutputFile << pair->first << ": \t";
            mOutputFile << pair->second.getOutput() << "\n";
        }
    }

    mOutputFile << "-------------------------------------------------" << "\n\n";
}

