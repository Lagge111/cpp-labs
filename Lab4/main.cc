// Main class which creates the circuits.

#include <iostream>
#include <string>

using namespace std;

// Declaring the methods so that they can be used in the main method.
void circuit_1();
void circuit_2();
void circuit_3();

int iterations{};
int outputRows{};
double timeStep{};
double voltage{};

// Main method
int main(int argc, char **argv)
{
    iterations = stoi(argv[0]);
    outputRows = stoi(argv[1]);
    timeStep = stod(argv[2]);
    volt = stod(argv[3]);

    circuit_1();
}

// Method for creating circuit 1 from the example.
void circuit_1()
{
    Connection p, n, R124, R23;
    vector<Component*> net;
    net.push_back(new Battery("Bat", voltage, p, n));
    net.push_back(new Resistor("R1", 6, p, R124));
    net.push_back(new Resistor("R2", 4, R124, R23));
    net.push_back(new Resistor("R3", 8, R23, n));
    net.push_back(new Resistor("R4", 12, R124, n));
    Simulation s{};
    s.simulate(net, iterations, outputRows, timeStep);
    //deallocate_components(net);
}

// Method for creating circuit 2 from the example.
void circuit_2()
{
}

// Method for creating circuit 3 from the example.
void circuit_3()
{
}