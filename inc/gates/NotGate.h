#include "Vertex.h"

class NotGate : public Vertex {
private:
    NotGate();
    NotGate(std::string);

public:
    virtual ~NotGate();

public:
    // void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static NotGate m_cInstance;
};
