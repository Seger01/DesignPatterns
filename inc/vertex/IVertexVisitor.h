#ifndef IVIRTEXVISITOR_H
#define IVIRTEXVISITOR_H

#include <fstream>

class AndGate;
class OrGate;
class NandGate;
class NorGate;
class NotGate;
class XorGate;
class Input;
class Probe;

class IVertexVisitor {
public:
    virtual void visitAndGate(AndGate aAndGate, std::fstream aFile) = 0;
    virtual void visitOrGate(OrGate aOrGate, std::fstream aFile) = 0;
    virtual void visitNandGate(NandGate aNandGate, std::fstream aFile) = 0;
    virtual void visitNorGate(NorGate aNorGate, std::fstream aFile) = 0;
    virtual void visitNotGate(NotGate aNotGate, std::fstream aFile) = 0;
    virtual void visitXorGate(XorGate aXorGat, std::fstream aFile) = 0;
    virtual void visitInput(Input aInput, std::fstream aFile) = 0;
    virtual void visitProbe(Probe aProbe, std::fstream aFile) = 0;
};
#endif // IVIRTEXVISITOR_H
