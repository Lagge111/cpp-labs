// Main class which creates the circuits.

#include <iostream>
#include <string>

#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Simulation.h"

using namespace std;

// Declaring the methods so that they can be used in the main method.
void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_2();
void circuit_3();

int iterations{};
int outputRows{};
double timeStep{};
double voltage{};

// Main method
int main(int argc, char **argv)
{
    cout << "Main" << endl;
    iterations = stoi(argv[1]);
    outputRows = stoi(argv[2]);
    timeStep = stod(argv[3]);
    voltage = stod(argv[4]);

    circuit_1(iterations, outputRows, timeStep, voltage);
}

// Method for creating circuit 1 from the example.
void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    cout << "Circuit_1 - 1" << endl;
    Connection p, n, r124, r23;
    vector<Component *> net;
    cout << "Circuit_1 - 2" << endl;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 6, &p, &r124));
    net.push_back(new Resistor("R2", 4, &r124, &r23));
    net.push_back(new Resistor("R3", 8, &r23, &n));
    net.push_back(new Resistor("R4", 12, &r124, &n));
    cout << "Circuit_1 - 3" << endl;
    Simulation simulation{};
    cout << "Circuit_1 - 4" << endl;
    simulation.simulate(net, iterations, outputRows, timeStep);
    // deallocate_components(net);
}

// Method for creating circuit 2 from the example.
void circuit_2()
{
}

// Method for creating circuit 3 from the example.
void circuit_3()
{
}