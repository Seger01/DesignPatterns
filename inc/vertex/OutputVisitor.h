#ifndef OUTPUTVISITOR_H
#define OUTPUTVISITOR_H

#include "IOutputVisitor.h"
#include <fstream>

class OutputVisitor : public IOutputVisitor {
public:
    OutputVisitor();
    ~OutputVisitor();

public:
    int visitInput(Input *aInput) override;
    int visitProbe(Probe *aProbe) override;
};
#endif // OUTPUTVISITOR_H
