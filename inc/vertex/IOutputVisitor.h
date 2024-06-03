#ifndef IOUTPUTVISITOR_H
#define IOUTPUTVISITOR_H

class Input;
class Probe;
class Vertex;

class IOutputVisitor {
public:
    virtual ~IOutputVisitor() = default;
    virtual int visitInput(Input* aInput) = 0;
    virtual int visitProbe(Probe* aProbe) = 0;
    virtual int visitVertex(Vertex* aVertex) = 0;
};
#endif // IOUTPUTVISITOR_H
