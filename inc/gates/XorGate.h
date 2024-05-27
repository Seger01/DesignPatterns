#include "Vertex.h"

class XorGate : public Vertex {
public:
    XorGate();
    virtual ~XorGate();

    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
};