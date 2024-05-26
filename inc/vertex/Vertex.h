class Vertex {
public:
    virtual ~Vertex() = default;
    virtual void setInput(int, bool) = 0;
};