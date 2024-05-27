#include "Vertex.h"

class AndGate : public Vertex {
public:
    AndGate();
    virtual ~AndGate();

    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
};