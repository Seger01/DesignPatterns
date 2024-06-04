/**
 ************************************************************
 * @file Input.h
 *
 * This file contains the definition of the Input class,
 * which is a derived class from Vertex and represents an
 * input in a digital circuit simulation.
 *
 */

#ifndef INPUT_H
#define INPUT_H

#include "Vertex.h"

/**
 ************************************************************
 * @class Input
 *
 * @brief Represents an input vertex in a circuit.
 *
 * The Input class represents a vertex in a circuit that serves
 * as an input. It inherits from the Vertex class and provides
 * methods to set and get input values.
 *
 * @author Seger01
 * @date 04/06/2024
 */
class Input : public Vertex {
private:
    int mValue = -1;

private:
    Input();
    Input(std::string);

public:
    ~Input();

    void setInput(int aIndex, int aValue) override;
    int getOutput() override;

public:                                        // Inherited methods
    void setAmountInputs(unsigned) override {} // Unused in input, not relevant
    std::string whoAmI() override;

    Vertex* clone() const override;

    void setOutput() override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

public: // Other methods
    void setValue(bool);

private:
    static Input m_cInstance;
};

#endif // INPUT_H
