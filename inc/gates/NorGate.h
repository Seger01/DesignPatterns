#include "Vertex.h"

class NorGate : public Vertex {
private:
    NorGate();
    NorGate(std::string);
public:
    virtual ~NorGate();

public:
    void setInput(unsigned, bool) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
std::string whoAmI() override;

    Vertex *clone() const override;

private:
    static NorGate m_cInstance;
};