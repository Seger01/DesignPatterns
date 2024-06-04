/**
 ************************************************************
 * @file VertexFactory.h
 *
 * This file contains the definition of the VertexFactory template
 * class, which provides a low binding factory method to create
 * instances of various gate classes derived from Vertex.
 *
 */

#pragma once

#include <assert.h>
#include <map>

/**
 ************************************************************
 * @namespace Factory
 *
 * The Factory namespace contains the VertexFactory template
 * class, which provides a mechanism for creating instances of
 * various gate classes derived from Vertex based on a unique ID.
 *
 */
namespace Factory {

/**
 ************************************************************
 * @class VertexFactory
 *
 * The VertexFactory template class provides a mechanism to create
 * instances of classes derived from Vertex based on a unique ID.
 * It uses a map to associate IDs with class prototypes and offers
 * methods to assign and create instances.
 *
 * @tparam ID The type of the unique identifier used for the classes
 * @tparam Class The base class type for the classes to be created
 *
 */
template <typename ID, typename Class> class VertexFactory {
private:
    VertexFactory() = default;
    virtual ~VertexFactory() = default;

private:
    static void assign(const ID&, const Class*);

public:
    static Class* create(const ID&);

private:
    /**
     * @brief Typedef for the map of IDs to class prototypes
     */
    typedef std::map<ID, const Class*> FactoryMap;

    static FactoryMap& getMap();

private:
    friend Class;
};

#include "VertexFactory.hpp"
} // namespace Factory