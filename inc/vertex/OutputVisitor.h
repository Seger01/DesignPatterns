/**
 ************************************************************
 * @file OutputVisitor.h
 *
 * Defines the OutputVisitor class for visiting different types 
 * of vertices in a circuit and performing output-related operations.
 *
 * @author Sean Groenenboom
 * @date June 4, 2024
 */
#ifndef OUTPUTVISITOR_H
#define OUTPUTVISITOR_H

#include "IOutputVisitor.h"
#include <fstream>

/**
 ************************************************************
 * @class OutputVisitor
 * 
 * @brief Implementation for the visitor pattern
 *
 * Implementation for the visitor pattern, allowing operations to be 
 * performed on different types of vertices in a circuit.
 */
class OutputVisitor : public IOutputVisitor {
public:
    OutputVisitor();
    ~OutputVisitor();

public:
    int visitInput(Input *aInput) override;
    int visitProbe(Probe *aProbe) override;
    int visitVertex(Vertex* aVertex) override;
};
#endif // OUTPUTVISITOR_H
