#include "Vertex.h"

class XorGate : public Vertex {
private:
    XorGate();
    XorGate(int);
public:
    virtual ~XorGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;

    Vertex *clone() const override;

private:
    static XorGate m_cInstance;
};