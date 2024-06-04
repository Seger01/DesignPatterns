/**
 ************************************************************
 * @file NotGate.h
 *
 * This file contains the definition of the NotGate class,
 * which is a derived class from Vertex and represents a
 * NOT logic gate in a digital circuit simulation.
 *
 */

#include "Vertex.h"

/**
 ************************************************************
 * @class NotGate
 *
 * @brief Represents a logical not gate
 *
 * The NotGate class inherits from the Vertex class and
 * represents a NOT logic gate. It overrides several
 * methods from the Vertex class to implement specific
 * behaviors for a NOT gate, such as calculating the output
 * based on its inputs and cloning the gate.
 *
 */
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
