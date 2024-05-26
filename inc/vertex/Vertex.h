#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
public:
    virtual ~Vertex() = default;
    virtual void setInput(int, bool) = 0;
};

#endif // VERTEX_H