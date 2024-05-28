#pragma once

#include <vector>

class Vertex {
private:
    int state = -1;
    std::vector<Vertex*> observers;
    std::vector<Vertex*> subjects;

public:
    Vertex();
    // Vertex(Vertex* subject, int aObserverIndex) : subject(subject) { subject->subscribe(aObserverIndex, this); }

    virtual ~Vertex();

    void subscribe(Vertex* observer);
    void unsubscribe(Vertex* observer);

    void addSubject(Vertex* subject);
    void removeSubject(Vertex* subject);

    void notify();

    void setState(int state);

    virtual void setInput(int aIndex, int value);

    virtual int getOutput();

    virtual void update();
};
