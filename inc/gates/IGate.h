#include "Vertex.h"

class IGate : public Vertex {
public:
    virtual ~IGate()  {};
    virtual void setInput(int, bool) override = 0;
    virtual int getOutput() = 0;
    virtual void setAmountInputs(int) = 0;
protected:
    int *mInput;
    int mOutput;
    int mAmountInputs = -1;

    const unsigned mMinInputs = 0;
    const unsigned mMaxInputs = 0;
};