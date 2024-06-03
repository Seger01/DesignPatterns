#include "Vertex.h"

class XorGate : public Vertex {
private:
    XorGate();
    XorGate(std::string);

public:
    virtual ~XorGate();

public:
    void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static XorGate m_cInstance;
};
