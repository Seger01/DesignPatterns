#include "IGate.h"

class AndGate : public IGate {
public:
    AndGate();
    virtual ~AndGate();

    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;
};