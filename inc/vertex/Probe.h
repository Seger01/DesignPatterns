/**
 ************************************************************
 * @file Probe.h
 *
 * This file contains the definition of the Probe class,
 * which is a derived class from Vertex and represents an
 * output in a digital circuit simulation.
 *
 */

#ifndef PROBE_H
#define PROBE_H

#include "Vertex.h"
/**
 ************************************************************
 * @class Probe
 *
 * @brief Represents a probe vertex in a circuit.
 *
 * The Probe class represents a vertex in a circuit that serves
 * as a probe to monitor the circuit's behavior. It inherits from
 * the Vertex class and provides methods to set and get input values
 * and retrieve the output value.
 *
 * @author Seger01
 * @date 04/06/2024
 */
class Probe : public Vertex {
private:
    int mValue = -1;
    static Probe m_cInstance;

private:
    Probe();
    Probe(std::string);

public:
    ~Probe();

    using Vertex::Vertex;
    void setInput(int aIndex, int aValue) override;
    int getValue();
    int getOutput() override;
    std::string whoAmI() override;

    int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) override;

    virtual Vertex* clone() const override;
};

#endif // PROBE_H
