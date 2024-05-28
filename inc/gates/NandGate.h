#include "Vertex.h"

class NandGate : public Vertex {
private:
    NandGate();
    NandGate(std::string);
public:
    virtual ~NandGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex *clone() const override;

private:
    static NandGate m_cInstance;
};