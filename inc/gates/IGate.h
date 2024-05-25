#include "Vertex.h"

class IGate : public Vertex {
public:
    virtual void setInput(int, bool) override = 0;
    virtual int getOutput() = 0;
    virtual void setAmountInputs(int) = 0;
private:
    int *mInput;
    int mOutput;
    int mAmountInputs;

    const unsigned mMinInputs;
    const unsigned mMaxInputs;
};