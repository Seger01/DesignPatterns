#include "Vertex.h"

class XorGate : public Vertex {
private:
    XorGate();
    XorGate(std::string);
public:
    virtual ~XorGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
std::string whoAmI() override;

    Vertex *clone() const override;

private:
    static XorGate m_cInstance;
};