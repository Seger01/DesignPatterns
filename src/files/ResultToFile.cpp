/**
 ************************************************************
 * @file ResultToFile.cpp
 *
 * Implements the ResultToFile class for managing the writing of circuit
 * results to an output file.
 *
 * @autor Sean Groenenboom
 * @date June 4, 2024
 */

#include "ResultToFile.h"

#include "Circuit.h"
#include "OutputVisitor.h"

#include <ctime>
#include <filesystem>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

/**
 ************************************************************
 * @brief Constructor for ResultToFile
 *
 * Initializes the ResultToFile object by setting the file open status to false
 * and generating the file.
 */
ResultToFile::ResultToFile() {
    mFileIsOpen = false;
    generateFile();
}

/**
 ************************************************************
 * @brief Destructor for ResultToFile
 *
 * Closes the file if it is open.
 */
ResultToFile::~ResultToFile() {
    if (mFileIsOpen) {
        closeFile();
    }
}

/**
 ************************************************************
 * @brief Generates the output file
 *
 * Ensures the output directory exists and creates a new file
 * with a timestamp in its name.
 */
void ResultToFile::generateFile() {
    // Ensure the output directory exists
    std::string outputDir = OUTPUTDIR;
    if (!std::filesystem::exists(outputDir)) {
        std::filesystem::create_directory(outputDir);
    }

    // Create a filename with a timestamp
    std::ostringstream oss;
    std::time_t now = std::time(nullptr);
    oss << outputDir << "/circuitOutput_" << std::put_time(std::localtime(&now), "%Y_%m_%d_%H:%M:%S") << ".txt";
    mFilename = oss.str();
}

/**
 ************************************************************
 * @brief Opens the output file
 *
 * Opens the output file in append mode if it is not already open.
 * Prints an error message if the file fails to open.
 */
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

/**
 ************************************************************
 * @brief Closes the output file
 *
 * Closes the output file if it is open and sets the file open status to false.
 */
void ResultToFile::closeFile() {
    if (mFileIsOpen) {
        mOutputFile.close();
        mFileIsOpen = false;
    }
}

/**
 ************************************************************
 * @brief Writes the simulation output to the file
 *
 * Writes the input and output values of the circuit to the file.
 * Ensures the file is open before writing.
 */
void ResultToFile::writeOutput() {
    std::map<std::string, Vertex*> data = Circuit::getInstance().getVertexMap();
    OutputVisitor outputVisitor;

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
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); ++iterator) {
        if (iterator->second != nullptr) {                                   // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 1) { // Check if it is an input
                mOutputFile << iterator->first << ": \t";
                mOutputFile << iterator->second->getOutput() << "\n";
            }
        }
    }

    // Output values
    mOutputFile << "\n"
                << "Output:" << "\n";
    for (std::map<std::string, Vertex*>::iterator iterator = data.begin(); iterator != data.end(); ++iterator) {
        if (iterator->second != nullptr) {                                   // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 2) { // Check if it is a probe
                mOutputFile << iterator->first << ": \t";
                mOutputFile << iterator->second->getOutput() << "\t";
                mOutputFile << "propagation delay is: " << iterator->second->getPropagationDelay() << " us \n";
            }
        }
    }

    mOutputFile << "-------------------------------------------------" << "\n\n";
}