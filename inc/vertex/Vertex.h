#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Vertex {
private:
    int id;
    std::string name;

public:
    Vertex(int id = 0, const std::string &name = "Default") : id(id), name(name) {}

    int getInput();
    int getOutput();

    std::string toString() const {
        return "Vertex(id: " + std::to_string(id) + ", name: " + name + ")";
    }
};

#endif // VERTEX_H
