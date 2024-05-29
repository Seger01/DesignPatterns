#ifndef IOUTPUTVISITOR_H
#define IOUTPUTVISITOR_H

#include <fstream>

class Input;
class Probe;

class IOutputVisitor {
public:
    virtual int visitInput(Input *aInput);
    virtual int visitProbe(Probe *aProbe);
};
#endif // IOUTPUTVISITOR_H
