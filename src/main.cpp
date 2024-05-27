#include "VertexFactory.h"
#include "Vertex.h"
#include <iostream>

int main() {
    Vertex *pVertex = Factory::VertexFactory<int,Vertex>::create(1);

    if (pVertex != nullptr) {
        pVertex->getOutput();
        delete pVertex;
    }
    return 0;
}
