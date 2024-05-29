#include "Vertex.h"

class OrGate : public Vertex {
private:
    OrGate();
    OrGate(std::string);

public:
    virtual ~OrGate();

public:
    void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

private:
    static OrGate m_cInstance;
};
