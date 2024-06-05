#pragma once
#include "VertexFactory.h"

/**
 * @brief Assign a class prototype to an ID
 *
 * This method associates a unique ID with a class prototype.
 *
 * @param[in] cID - The unique identifier for the class
 * @param[in] pClass - The class prototype to associate with the ID
 */
template <typename ID, typename Class>
void Factory::VertexFactory<ID, Class>::assign(const ID& cID, const Class* pClass) {
    static FactoryMap& cMap = getMap();

    assert(cMap.find(cID) == cMap.end());

    cMap[cID] = pClass;
}

/**
 * @brief Create an instance of a class based on the ID
 *
 * This method creates a new instance of a class associated with
 * the given ID.
 *
 * @param[in] cID - The unique identifier for the class
 *
 * @return A pointer to the newly created instance of the class
 */
template <typename ID, typename Class> Class* Factory::VertexFactory<ID, Class>::create(const ID& cID) {
    static FactoryMap& cMap = getMap();
    typename FactoryMap::iterator iFind = cMap.find(cID);

    if (iFind == cMap.end())
        return nullptr;
    else
        return iFind->second->clone();
}

/**
 * @brief Get the map of IDs to class prototypes
 *
 * This method returns a reference to the static map that
 * associates IDs with class prototypes.
 *
 * @return A reference to the static FactoryMap
 */
template <typename ID, typename Class>
typename Factory::VertexFactory<ID, Class>::FactoryMap& Factory::VertexFactory<ID, Class>::getMap() {
    static FactoryMap cMap;
    return cMap;
}
