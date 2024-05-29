#include "OutputVisitor.h"

#include "AndGate.h"
#include "Input.h"
#include "NandGate.h"
#include "NorGate.h"
#include "NotGate.h"
#include "OrGate.h"
#include "Probe.h"
#include "XorGate.h"

OutputVisitor::OutputVisitor(/* args */) {}

OutputVisitor::~OutputVisitor() {}

void OutputVisitor::visitAndGate(AndGate aAndGate, std::fstream aFile) {}

void OutputVisitor::visitOrGate(OrGate aOrGate, std::fstream aFile) {}

void OutputVisitor::visitNandGate(NandGate aNandGate, std::fstream aFile) {}

void OutputVisitor::visitNorGate(NorGate aNorGate, std::fstream aFile) {}

void OutputVisitor::visitNotGate(NotGate aNotGate, std::fstream aFile) {}

void OutputVisitor::visitXorGate(XorGate aXorGat, std::fstream aFile) {}

void OutputVisitor::visitInput(Input aInput, std::fstream aFile) {
    // aFile << iterator << ": \t";
    aFile << aInput.getOutput() << "\n";
}

void OutputVisitor::visitProbe(Probe aProbe, std::fstream aFile) {
    // aFile << iterator->first << ": \t";
    aFile << aProbe.getOutput() << "\n";
}
