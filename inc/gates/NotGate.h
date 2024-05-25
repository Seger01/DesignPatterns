#include "IGate.h"

class NotGate : public IGate {
public:
    NotGate();
    virtual ~NotGate();

    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;
};