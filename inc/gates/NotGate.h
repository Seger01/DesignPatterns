#include "Vertex.h"

class NotGate : public Vertex {
private:
    NotGate();
    NotGate(std::string);
public:
    virtual ~NotGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
std::string whoAmI() override;

    Vertex *clone() const override;

private:
    static NotGate m_cInstance;
};