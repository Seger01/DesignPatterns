#include "ResultToFile.h"

#include "Circuit.h"
#include "Input.h"
#include "OutputVisitor.h"
#include "Probe.h"
#include "Vertex.h"

#include <map>
#include <string>

#include <ctime>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <sstream>

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

void ResultToFile::writeOutput() {
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    OutputVisitor outputVisitor;

    openFile(); // Ensure the file is open before writing

    if (!mOutputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    static int simCount = 1;
    mOutputFile << "-------------------------------------------------"
                << "\n";
    mOutputFile << "Sim " << simCount++ << "\n";

    // Input values
    mOutputFile << "Input:"
                << "\n";
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second != nullptr) {                                   // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 1) { // Check if it is an input
                mOutputFile << iterator->first << ": \t";
                mOutputFile << iterator->second->getOutput() << "\n";
            }
        }
    }

    // Output values
    mOutputFile << "\n"
                << "Output:"
                << "\n";
    std::cout << "Start" << std::endl;
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second != nullptr) {                                   // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 2) { // Check if it is a probe
                mOutputFile << iterator->first << ": \t";
                mOutputFile << iterator->second->getOutput() << "\n";
                std::cout << "Calculated Propagation Delay: " << iterator->second->getPropagationDelay() << std::endl;
            }
        }
    }
    std::cout << "End" << std::endl;

    mOutputFile << "-------------------------------------------------"
                << "\n\n";
}
