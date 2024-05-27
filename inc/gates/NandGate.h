#include "Vertex.h"

class NandGate : public Vertex {
public:
    NandGate();
    virtual ~NandGate();

    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
};