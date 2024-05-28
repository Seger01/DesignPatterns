#include "Vertex.h"

class Probe : public Vertex {
private:
    int mValue = -1;

public:
    using Vertex::Vertex;
    virtual void setInput(int aIndex, int aValue) override;
    bool getValue();
};
