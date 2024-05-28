#include <iostream>
#include <map>

#include "Input.h"
#include "Probe.h"
#include "Vertex.h"

void vertexObserverTest() {
    std::cout << "Start!" << std::endl;

    Input subject(1234);

    Vertex observer1;
    Vertex observer2;

    observer1.addSubject(&subject);

    observer2.addSubject(&observer1);
    observer2.addSubject(&subject);

    Probe probe;

    probe.addSubject(&observer1);

    std::cout << "setstate(1)" << std::endl;
    subject.setState(1);
    std::cout << "setstate(2)" << std::endl;
    subject.setState(2);
}

class Circuit {
private:
    std::map<std::string, Vertex> mMapVertexes;

private:
    // Private constructor to prevent instantiation
    Circuit() { std::cout << "Circuit singleton instance created." << std::endl; }

    // Private destructor
    ~Circuit() { std::cout << "Circuit singleton instance destroyed." << std::endl; }

public:
    int state = 0;
    // Delete copy constructor and assignment operator to prevent copying
    Circuit(const Circuit&) = delete;
    Circuit& operator=(const Circuit&) = delete;

    // Static method to get the single instance of the class
    static Circuit& getInstance() {
        static Circuit instance;
        return instance;
    }

    // Example method
    void showMessage() { std::cout << "Circuit singleton instance method called." << state << std::endl; }
};

int main() {
    // Access the singleton instance and call its method
    Circuit& circuit1 = Circuit::getInstance();
    circuit1.state = 1234;
    circuit1.showMessage();

    // Another reference to the singleton instance
    Circuit& circuit2 = Circuit::getInstance();
    circuit2.showMessage();

    return 0;
}
