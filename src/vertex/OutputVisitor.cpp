#include "OutputVisitor.h"

#include "Input.h"
#include "Probe.h"


OutputVisitor::OutputVisitor(/* args */) {}

OutputVisitor::~OutputVisitor() {}

int OutputVisitor::visitInput(Input *aInput) {
    return 1;
}

int OutputVisitor::visitProbe(Probe *aProbe) {
    return 2;

}
