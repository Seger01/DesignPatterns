/**
 ************************************************************
 * @file NandGate.h
 *
 * This file contains the definition of the NandGate class,
 * which is a derived class from Vertex and represents a
 * NAND logic gate in a digital circuit simulation.
 *
 */

#include "Vertex.h"

/**
 ************************************************************
 * @class NandGate
 *
 * The NandGate class inherits from the Vertex class and 
 * represents a NAND logic gate. It overrides several 
 * methods from the Vertex class to implement specific 
 * behaviors for a NAND gate, such as calculating the output 
 * based on its inputs and cloning the gate.
 *
class NandGate : public Vertex {
private:
    NandGate();
    NandGate(std::string);

public:
    virtual ~NandGate();

public:
    // void setInput(int, int) override;
    int getOutput() override;
    void setAmountInputs(unsigned) override;
    std::string whoAmI() override;

    Vertex* clone() const override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

private:
    static NandGate m_cInstance;
};
