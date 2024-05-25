#include "IGate.h"

class NandGate : public IGate {
public:
    NandGate();
    virtual ~NandGate();

    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;
};