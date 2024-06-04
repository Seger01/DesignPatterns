/**
 ************************************************************
 * @file NorGate.h
 *
 * This file contains the definition of the NorGate class,
 * which is a derived class from Vertex and represents a
 * NOR logic gate in a digital circuit simulation.
 *
 */

#include "IOutputVisitor.h"
#include "Vertex.h"

/**
 ************************************************************
 * @class NorGate
 *
 * The NorGate class inherits from the Vertex class and
 * represents a NOR logic gate. It overrides several
 * methods from the Vertex class to implement specific
 * behaviors for a NOR gate, such as calculating the output
 * based on its inputs and cloning the gate.
 *
 */
class NorGate : public Vertex {
private:
    NorGate();
    NorGate(std::string);

public:
    virtual ~NorGate();

public:
    // void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static NorGate m_cInstance;
};
