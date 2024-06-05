 /**
 ************************************************************
 * @file IOutputVisitor.h
 *
 * Defines the IOutputVisitor interface for visiting different types 
 * of vertices in a circuit, such as Input, Probe, and Vertex.
 *
 * @author Sean Groenenboom
 * @date June 4, 2024
 */
#ifndef IOUTPUTVISITOR_H
#define IOUTPUTVISITOR_H

class Input;
class Probe;
class Vertex;

/**
 ************************************************************
 * @class IOutputVisitor
 * 
 * @brief Interface for the visitor pattern
 *
 * Interface for the visitor pattern, allowing operations to be 
 * performed on different types of vertices in a circuit.
 */
class IOutputVisitor {
public:
    virtual ~IOutputVisitor() = default;
    virtual int visitInput(Input* aInput) = 0;
    virtual int visitProbe(Probe* aProbe) = 0;
    virtual int visitVertex(Vertex* aVertex) = 0;
};
#endif // IOUTPUTVISITOR_H
