#include "Circuit.h"

Circuit* Circuit::mCircuit = nullptr;

Circuit& Circuit::getInstance() {
    if (mCircuit == nullptr) {
        mCircuit = new Circuit;
    }

    return *mCircuit;
}

std::map<std::string, Vertex*>& Circuit::getVertexMap() { return mMapVertexes; }

void Circuit::runSim() {

    std::cout << "mapVertexes.size " << this->mMapVertexes.size() << std::endl;
    std::cout << "Start" << std::endl;

    for (const auto& pair : mMapVertexes) {
        if (pair.second == nullptr) {
            std::cout << "Key: " << pair.first << ", Value: "
                      << "nullptr" << std::endl;
        } else {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second->getOutput() << std::endl;
        }
    }

    std::cout << "END" << std::endl;
    return;
}
