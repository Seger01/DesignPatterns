/**
 ************************************************************
 * @file OrGate.h
 *
 * This file contains the definition of the OrGate class,
 * which is a derived class from Vertex and represents an
 * OR logic gate in a digital circuit simulation.
 *
 */

#include "Vertex.h"

/**
 ************************************************************
 * @class OrGate
 *
 * @brief Represents a logical or gate
 *
 * The OrGate class inherits from the Vertex class and
 * represents an OR logic gate. It overrides several
 * methods from the Vertex class to implement specific
 * behaviors for an OR gate, such as calculating the output
 * based on its inputs and cloning the gate.
 *
 */
class OrGate : public Vertex {
private:
    OrGate();
    OrGate(std::string);

public:
    virtual ~OrGate();

public:
    // void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static OrGate m_cInstance;
};
