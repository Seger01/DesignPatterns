#include "Vertex.h"

class AndGate : public Vertex {
private:
    AndGate();
    AndGate(std::string);

public:
    virtual ~AndGate();

public:
    virtual void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor aIOutputVisitor) override { return -1; };

private:
    static AndGate m_cInstance;
};
