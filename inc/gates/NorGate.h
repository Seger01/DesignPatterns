#include "Vertex.h"
#include "IOutputVisitor.h"

class NorGate : public Vertex {
private:
    NorGate();
    NorGate(std::string);

public:
    virtual ~NorGate();

public:
    void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static NorGate m_cInstance;
};
