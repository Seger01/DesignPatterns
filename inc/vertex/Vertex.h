class Vertex {
protected:
    Vertex();
    Vertex(int);
public:
    virtual ~Vertex() = default;

public:
    virtual void setInput(int, bool) = 0;

public:
    virtual Vertex *clone() const = 0;
};