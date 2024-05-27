#include "Vertex.h"

class OrGate : public Vertex {
private:
    OrGate();
    OrGate(int);
public:
    virtual ~OrGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;

    Vertex *clone() const override;

private:
    static OrGate m_cInstance;
};