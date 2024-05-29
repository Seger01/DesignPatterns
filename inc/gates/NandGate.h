#include "Vertex.h"

class NandGate : public Vertex {
private:
    NandGate();
    NandGate(std::string);

public:
    virtual ~NandGate();

public:
    void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor aIOutputVisitor) override {return -1;};

private:
    static NandGate m_cInstance;
};
