#include "CircuitSimulator.h"

#include <filesystem>
#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
    std::string inputFilePath;

    if (argc > 2) {
        std::cout << "ERROR wrong function usage" << std::endl;
        std::cout << "usage: ./executable [inputfile.txt]" << std::endl;
        return 1;
    }

    if (argc > 1) {
        // Extract the path from the first argument
        std::string argPath = argv[1];
        std::filesystem::path p(argPath);

        // Check if the path exists
        if (std::filesystem::exists(p)) {
            std::cout << "Path provided: " << p << std::endl;
            inputFilePath = p;
        } else {
            std::cerr << "Warning: Invalid path provided!" << std::endl;
            // Print usage instructions here
        }
    } else {
        // No arguments provided, set a standard path
        std::filesystem::path standardPath = "inputfile.txt";
        inputFilePath = standardPath;
        std::cout << "Using standard path: " << standardPath << std::endl;
    }

    CircuitSimulator circuitSimulator(inputFilePath);

    circuitSimulator.run();

    return 0;
}
