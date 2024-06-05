#ifndef VERTEX_H
#define VERTEX_H

#include "IOutputVisitor.h"
#include <iostream>
#include <vector>

/**
 ************************************************************
 * @class Vertex
 *
 * @brief Represents a vertex in a circuit.
 *
 * The Vertex class represents a vertex in a circuit and provides
 * methods for managing inputs, outputs, and propagation delays.
 * It also supports observer pattern for notifying observers of changes.
 *
 * @author Seger01
 * @date 04/06/2024
 */
class Vertex {
private:
    int state = -1;
    int mValue = -1;

public:
    std::vector<Vertex*> observers;
    std::vector<Vertex*> subjects;

    Vertex();
    Vertex(std::string);

    virtual ~Vertex();

    void subscribe(Vertex* observer);
    void unsubscribe(Vertex* observer);

    void addSubject(Vertex* subject);
    void removeSubject(Vertex* subject);

    void notify();

    virtual void setState(int state);

    virtual void setInput(int aIndex, int value);
    // virtual void setInput(unsigned aIndex, bool value);

    virtual int getOutput();
    virtual int getPropagationDelay();

    virtual void setOutput(){};

    virtual void update();

    virtual void reset() {
        mOutput = -1;

        mCurrentPropogationDelay = 0;
    };

    virtual int acceptOutputVisitor(IOutputVisitor& aIOutputVisitor) { return -1; };

protected:
public:
    virtual void setAmountInputs(unsigned) { std::cout << "setAmountInputs()" << std::endl; };
    virtual int bumpAmountInputs();
    virtual std::string whoAmI();

public:
    virtual Vertex* clone() const { return new Vertex; }

protected:
    int* mInput;
    int mOutput = -1;
    int mAmountInputs = -1;
    int mAmountInputsSet = 0;

    unsigned mMinInputs = 0;
    unsigned mMaxInputs = 0;

    int mCurrentPropogationDelay = 0;
    int mAddingPropagationDelay = 10;
};

#endif // VERTEX_H
