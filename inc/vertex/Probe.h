#ifndef PROBE_H
#define PROBE_H

#include "Vertex.h"

class Probe : public Vertex {
private:
    int mValue = -1;
    static Probe m_cInstance;

private:
    Probe();
    Probe(std::string);

public:
    ~Probe();

    using Vertex::Vertex;
    void setInput(int aIndex, int aValue) override;
    int getValue();
    int getOutput() override;
    std::string whoAmI() override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

    virtual Vertex* clone() const override;
};

#endif // PROBE_H
