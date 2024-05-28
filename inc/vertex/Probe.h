#pragma once
#ifndef PROBE_H
#define PROBE_H

#include "Vertex.h"

class Probe : public Vertex {
private:
    int mValue = -1;
    static Probe m_cInstance;

private:
    Probe();
    Probe(int);
public:
    ~Probe();

    using Vertex::Vertex;
    virtual void setInput(int aIndex, int aValue) override;
    int getValue();

    virtual Vertex* clone() const override;
};

#endif // PROBE_H
