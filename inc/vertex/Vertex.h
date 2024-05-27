class Vertex {
protected:
    Vertex();
    Vertex(int);
public:
    virtual ~Vertex();

public:
    virtual void setInput(unsigned, bool) = 0;
    virtual int getOutput() = 0;
    virtual void setAmountInputs(unsigned) = 0;

public:
    virtual Vertex *clone() const = 0;

protected:
    int *mInput;
    int mOutput;
    int mAmountInputs = -1;

    unsigned mMinInputs = 0;
    unsigned mMaxInputs = 0;
};