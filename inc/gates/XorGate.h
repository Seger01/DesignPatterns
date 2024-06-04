/**
 ************************************************************
 * @file XorGate.h
 *
 * This file contains the definition of the XorGate class,
 * which is a derived class from Vertex and represents an
 * XOR logic gate in a digital circuit simulation.
 *
 */

#include "Vertex.h"

/**
 ************************************************************
 * @class XorGate
 *
 * @brief Represents a logical xor gate
 *
 * The XorGate class inherits from the Vertex class and
 * represents an XOR logic gate. It overrides several
 * methods from the Vertex class to implement specific
 * behaviors for an XOR gate, such as calculating the output
 * based on its inputs and cloning the gate.
 *
 */
class XorGate : public Vertex {
private:
    XorGate();
    XorGate(std::string);

public:
    virtual ~XorGate();

public:
    // void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static XorGate m_cInstance;
};
