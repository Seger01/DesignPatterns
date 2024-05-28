#include "Vertex.h"

class Input : public Vertex {
private:
    int mValue = -1;

private:
public:
    Input(int aStartValue);

    virtual void setInput(int aIndex, int aValue) override;
    virtual int getOutput() override;
};
