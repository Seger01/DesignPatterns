#include "IGate.h"

class OrGate : public IGate {
public:
    OrGate();
    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;

private:
    const unsigned mMinInputs = 2;
    const unsigned mMaxInputs = 3;
};