#include "IGate.h"

class XorGate : public IGate {
public:
    XorGate();
    virtual ~XorGate();

    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;
};