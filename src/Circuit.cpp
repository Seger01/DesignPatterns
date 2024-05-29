#include "Circuit.h"

Circuit* Circuit::mCircuit = nullptr;
;

Circuit* Circuit::getInstance() {
    if (mCircuit == nullptr) {
        mCircuit = new Circuit;
    }

    return mCircuit;
}

std::map<std::string, Vertex*> Circuit::getVertexMap() { return mMapVertexes; }