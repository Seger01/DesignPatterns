#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include "IOutputVisitor.h"
class Vertex {
private:
    int state = -1;
    std::vector<Vertex*> observers;
    std::vector<Vertex*> subjects;

public:
    Vertex();
    Vertex(std::string);

    virtual ~Vertex();

    void subscribe(Vertex* observer);
    void unsubscribe(Vertex* observer);

    void addSubject(Vertex* subject);
    void removeSubject(Vertex* subject);

    void notify();

    void setState(int state);

    virtual void setInput(int aIndex, int value);
    // virtual void setInput(unsigned aIndex, bool value);

    virtual int getOutput();

    virtual void update();

    virtual void reset() {};

    virtual int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) {return -1;};

protected:
public:
    virtual void setAmountInputs(unsigned) { std::cout << "setAmountInputs()" << std::endl; };
    virtual int bumpAmountInputs();
    virtual std::string whoAmI();

public:
    virtual Vertex* clone() const { return new Vertex; }

protected:
    int* mInput;
    int mOutput;
    int mAmountInputs = -1;
    int mAmountInputsSet = 0;

    unsigned mMinInputs = 0;
    unsigned mMaxInputs = 0;
};

#endif // VERTEX_H
