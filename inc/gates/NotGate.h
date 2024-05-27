#include "Vertex.h"

class NotGate : public Vertex {
public:
    NotGate();
    virtual ~NotGate();

    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
};