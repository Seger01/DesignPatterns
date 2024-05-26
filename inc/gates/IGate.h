#include "Vertex.h"

class IGate : public Vertex {
public:
    virtual void setInput(int, bool) override = 0;
    virtual int getOutput() = 0;
    virtual void setAmountInputs(int) = 0;
protected:
    int *mInput;
    int mOutput;
    int mAmountInputs = -1;

    unsigned mMinInputs = 0;
    unsigned mMaxInputs = 0;
};