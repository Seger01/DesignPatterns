#ifndef OUTPUTVISITOR_H
#define OUTPUTVISITOR_H

#include "IVertexVisitor.h"
#include <fstream>

class OutputVisitor : public IVertexVisitor {
private:
    /* data */
public:
    OutputVisitor(/* args */);
    ~OutputVisitor();

public:
    void visitAndGate(AndGate aAndGate, std::fstream aFile) override;
    void visitOrGate(OrGate aOrGate, std::fstream aFile) override;
    void visitNandGate(NandGate aNandGate, std::fstream aFile) override;
    void visitNorGate(NorGate aNorGate, std::fstream aFile) override;
    void visitNotGate(NotGate aNotGate, std::fstream aFile) override;
    void visitXorGate(XorGate aXorGat, std::fstream aFile) override;
    void visitInput(Input aInput, std::fstream aFile) override;
    void visitProbe(Probe aProbe, std::fstream aFile) override;
};
#endif // OUTPUTVISITOR_H
