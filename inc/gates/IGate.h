#include "Vertex.h"

class IGate : public Vertex {
public:
    virtual void setInput(int, bool) override;
    virtual int getOutput();
    virtual void setAmountInputs(int);
private:
    int *mInput;
    int mOutput;
    int mAmountInputs;
    int mMinInputs;
    int mMaxInputs;
};