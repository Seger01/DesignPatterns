/**
 ************************************************************
 * @file AndGate.h
 *
 * This file contains the definition of the AndGate class,
 * which is a derived class from Vertex and represents an
 * AND logic gate in a digital circuit simulation.
 *
 */

#include "Vertex.h"

/**
 ************************************************************
 * @class AndGate
 *
 * @brief Represents a logical and gate
 *
 * The AndGate class inherits from the Vertex class and
 * represents an AND logic gate. It overrides several
 * methods from the Vertex class to implement specific
 * behaviors for an AND gate, such as calculating the output
 * based on its inputs and cloning the gate.
 *
 */
class AndGate : public Vertex {
private:
    AndGate();
    AndGate(std::string);

public:
    virtual ~AndGate();

public:
    // virtual void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static AndGate m_cInstance;
};
