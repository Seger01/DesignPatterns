#include "TextStrategy.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

/**
 ************************************************************
 * @brief Constructor for TextStrategy
 *
 * Initializes the TextStrategy object.
 */
TextStrategy::TextStrategy() {}

/**
 ************************************************************
 * @brief Destructor for TextStrategy
 *
 * Closes the input file if it is open.
 */
TextStrategy::~TextStrategy() { closeFile(); }

/**
 ************************************************************
 * @brief Removes all spaces from a string
 *
 * Removes all whitespace characters from the given string.
 *
 * @param[in] aString - The input string
 *
 * @return The string without spaces
 */
std::string TextStrategy::removeAllSpaces(const std::string& aString) {
    std::string result;
    for (char c : aString) {
        if (!isspace(static_cast<unsigned char>(c))) {
            result += c;
        }
    }
    return result;
}

/**
 ************************************************************
 * @brief Opens the input file
 *
 * Opens the specified input file for reading.
 *
 * @param[in] filename - The name of the file to open
 */
void TextStrategy::openFile(const std::string& filename) {
    mInputFile.open(filename);
    if (!mInputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
}

/**
 ************************************************************
 * @brief Closes the input file
 *
 * Closes the input file if it is open.
 */
void TextStrategy::closeFile() {
    if (mInputFile.is_open()) {
        mInputFile.close();
    }
}

/**
 ************************************************************
 * @brief Reads the vertices and edges from the file
 *
 * Reads the vertices and edges from the input file and populates the
 * corresponding maps.
 *
 * @param[inout] aVertexMap - Map of vertex names to types
 * @param[inout] aEdgeMap - Multimap of edge connections
 */
void TextStrategy::readFile(std::map<std::string, std::string>& aVertexMap,
                            std::multimap<std::string, std::string>& aEdgeMap) {
    std::string line;
    int lineNumber = 0;
    bool edgeFound = false;    // Flag to indicate if edge part of the file is found
    bool startReading = false; // Flag to indicate when to start reading

    // Read vertices
    while (std::getline(mInputFile, line)) {
        lineNumber++;
        // Check if the line contains "# Description of all the nodes"
        if (!startReading) {
            if (line.find("# Description of all the nodes") != std::string::npos) {
                startReading = true;
            }
            continue; // Skip lines until the start line is found
        }

        // Check if the line contains "# Description of all the edges"
        if (line.find("# Description of all the edges") != std::string::npos) {
            edgeFound = true;
            break; // Stop parsing when encountering this line
        }

        // Trim whitespaces
        line = removeAllSpaces(line);

        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        if (line.back() != ';') { // Check if line ends with ;
            std::cerr << "Error: Line " << lineNumber << " does not end with ;" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Find the position of the colon
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) {
            std::cerr << "Error: Line " << lineNumber << " does not have :" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Extract the substring before the colon
        std::string nodeName = line.substr(0, colonPos);
        if (nodeName.empty()) {
            std::cerr << "Error: Line " << lineNumber << " has empty node name" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Extract the substring after the colon
        std::string nodeType = line.substr(colonPos + 1);
        if (!nodeType.empty()) {
            nodeType.erase(nodeType.size() - 1);
        }

        // Check if it is an acceptable type
        if (stringSet.find(nodeType) == stringSet.end()) {
            std::cerr << "Error: Line " << lineNumber << " has invalid node type" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        aVertexMap.insert({nodeName, nodeType});
    }

    // Check if the start line was found
    if (!startReading) {
        std::cerr << "Error: Could not find '# Description of all the nodes' in the input file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (!edgeFound) {
        std::cerr << "Error: Could not find '# Description of all the edges' in the input file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Read edges
    while (std::getline(mInputFile, line)) {
        lineNumber++;

        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        // Trim whitespaces
        line = removeAllSpaces(line);
        if (line.back() != ';') { // Check if line ends with ;
            std::cerr << "Error: Line " << lineNumber << " does not end with ;" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Remove the ; from the string
        line.resize(line.size() - 1);

        // Find the position of the colon
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) {
            std::cerr << "Error: Line " << lineNumber << " does not have :" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Extract the substring before the colon
        std::string edgeBegin = line.substr(0, colonPos);
        if (edgeBegin.empty()) {
            std::cerr << "Error: Line " << lineNumber << " has empty node name" << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Read the edges from the colon position onwards
        std::stringstream stream(line.substr(colonPos + 1));
        std::string edgeEnd;
        while (std::getline(stream, edgeEnd, ',')) {
            aEdgeMap.insert({edgeBegin, edgeEnd});
        }
    }
}