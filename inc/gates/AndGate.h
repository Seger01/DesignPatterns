#include "Vertex.h"

class AndGate : public Vertex {
private:
    AndGate();
    AndGate(std::string);
public:
    virtual ~AndGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;

    Vertex *clone() const override;

private:
    static AndGate m_cInstance;
};