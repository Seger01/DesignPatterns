#include "OutputVisitor.h"

// #include "Input.h"
// #include "Probe.h"
// #include "Vertex.h"

OutputVisitor::OutputVisitor() {}

OutputVisitor::~OutputVisitor() {}

int OutputVisitor::visitInput(Input *aInput) {
    return 1;
}

int OutputVisitor::visitProbe(Probe *aProbe) {
    return 2;
}

int OutputVisitor::visitVertex(Vertex *aVertex) {
    return 3;
}
