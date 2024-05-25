#include "IGate.h"

class OrGate : public IGate {
public:
    OrGate();
    virtual ~OrGate();

    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;
};