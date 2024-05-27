#include "Vertex.h"
#include "VertexFactory.h"
#include <iostream>

Vertex::Vertex() {
    std::cout << "Vertex default constructor" << std::endl;
}

Vertex::Vertex(int id) {
    Factory::VertexFactory<int,Vertex>::assign(id,this); // Associate the ID of the child, so the factory knows which type of child to create
    std::cout << "Vertex assignment constructor" << std::endl;
}

Vertex::~Vertex() {
    std::cout << "Vertex destructor" << std::endl;
}