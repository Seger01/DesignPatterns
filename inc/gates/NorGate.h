#include "Vertex.h"

class NorGate : public Vertex {
private:
    NorGate();
    NorGate(int);
public:
    virtual ~NorGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;

    Vertex *clone() const override;

private:
    static NorGate m_cInstance;
};