#include "Vertex.h"

class NorGate : public Vertex {
public:
    NorGate();
    virtual ~NorGate();

    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
};