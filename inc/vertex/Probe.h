#ifndef PROBE_H
#define PROBE_H

#include "Vertex.h"

class Probe : public Vertex {
private:
    Probe();
    Probe(int);
public:
    ~Probe();

public: // Inherited methods
    void setInput(unsigned, bool) override;
    int getOutput() override {return 0;};                // Unused in probe, not relevant
    void setAmountInputs(unsigned) override {}  // Unused in probe, not relevant

    Vertex *clone() const override;
public: // Other methods
    int getValue();

private:
    static Probe m_cInstance;
    int mValue;
};

#endif // PROBE_H
