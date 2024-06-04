/**
 ************************************************************
 * @file OutputVisitor.cpp
 *
 * Implements the OutputVisitor class for visiting different types
 * of vertices in a circuit and performing output-related operations.
 *
 * @author Sean Groenenboom
 * @date June 4, 2024
 */
#include "OutputVisitor.h"

/**
 ************************************************************
 * @brief Constructor for OutputVisitor
 *
 * Initializes the OutputVisitor object.
 */
OutputVisitor::OutputVisitor() {}

/**
 ************************************************************
 * @brief Destructor for OutputVisitor
 *
 * Cleans up resources used by the OutputVisitor object.
 */
OutputVisitor::~OutputVisitor() {}

/**
 ************************************************************
 * @brief Visits an Input vertex
 *
 * Performs output-related operations for an Input vertex.
 *
 * @param[in] aInput - Pointer to the Input vertex to visit
 * @return 1
 */
int OutputVisitor::visitInput(Input* aInput) { return 1; }

/**
 ************************************************************
 * @brief Visits a Probe vertex
 *
 * Performs output-related operations for a Probe vertex.
 *
 * @param[in] aProbe - Pointer to the Probe vertex to visit
 * @return 2
 */
int OutputVisitor::visitProbe(Probe* aProbe) { return 2; }

/**
 ************************************************************
 * @brief Visits a Vertex
 *
 * Performs output-related operations for a general Vertex.
 *
 * @param[in] aVertex - Pointer to the Vertex to visit
 * @return 3
 */
int OutputVisitor::visitVertex(Vertex* aVertex) { return 3; }
