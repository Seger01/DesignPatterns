#ifndef INPUT_H
#define INPUT_H

#include "Vertex.h"
class Input : public Vertex
{
private:
    /* data */
public:
    Input(/* args */);
    ~Input();

    void setInput(unsigned, bool) override;
    int getInput();
};

#endif // INPUT_H
