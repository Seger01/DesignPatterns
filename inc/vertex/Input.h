#ifndef INPUT_H
#define INPUT_H

#include "Vertex.h"

class Input : public Vertex {
private:
    Input();
    Input(int);
public:
    ~Input();

public: // Inherited methods
    void setInput(unsigned, bool) override {}  // Unused in input, not relevant
    int getOutput() override;
    void setAmountInputs(unsigned) override {}  // Unused in input, not relevant

    Vertex *clone() const override;
public: // Other methods
    void setValue(bool);

private:
    static Input m_cInstance;
    int mValue;
};

#endif // INPUT_H
