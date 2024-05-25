#include "IGate.h"

class OrGate : public IGate {
public:
    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;

private:
    //const unsigned mMinInputs = 2;
};