#include "IGate.h"

class NorGate : public IGate {
public:
    NorGate();
    virtual ~NorGate();

    void setInput(int, bool) override;
    int getOutput() override;
    void setAmountInputs(int) override;
};