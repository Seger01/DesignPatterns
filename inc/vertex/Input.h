#ifndef INPUT_H
#define INPUT_H

#include "Vertex.h"

class Input : public Vertex {
private:
    int mValue = -1;

private:
    Input();
    Input(std::string);
public:
    ~Input();

    virtual void setInput(int aIndex, int aValue) override;
    virtual int getOutput() override;

public:                                        // Inherited methods
    void setAmountInputs(unsigned) override {} // Unused in input, not relevant
    std::string whoAmI() override;

    Vertex* clone() const override;

public: // Other methods
    void setValue(bool);

private:
    static Input m_cInstance;
};

#endif // INPUT_H
