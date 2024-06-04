#include "Circuit.h"
#include "OutputVisitor.h"

Circuit* Circuit::mCircuit = nullptr;

Circuit& Circuit::getInstance() {
    if (mCircuit == nullptr) {
        mCircuit = new Circuit;
    }

    return *mCircuit;
}

std::map<std::string, Vertex*>& Circuit::getVertexMap() { return mMapVertexes; }

void Circuit::runSim() {
    OutputVisitor outputVisitor;

    for (std::map<std::string, Vertex*>::iterator iterator = mMapVertexes.begin(); iterator != mMapVertexes.end(); iterator++) {
        if (iterator->second != nullptr) {                                   // Check for nullptr
            if (iterator->second->acceptOutputVisitor(outputVisitor) == 1) { // Check if it is an input
                iterator->second->setOutput();
            }
        }
    }

    std::cout << "END" << std::endl;
    return;
}
