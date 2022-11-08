
#include <iostream>
#include <string>

#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Simulation.h"

using namespace std;

// Declaring the methods so that they can be used in the main method.
void circuit_1();
void circuit_2();
void circuit_3();

int iterations{};
int outputRows{};
double timeStep{};
double voltage{};

// Main method. We should probably try-catch the command line arguments
int main(int argc, char **argv)
{
    iterations = stoi(argv[0]);
    outputRows = stoi(argv[1]);
    timeStep = stod(argv[2]);
    voltage = stod(argv[3]);

    circuit_1();
}

// Method for creating circuit 1 from the example.
void circuit_1()
{
    Connection p, n, r124, r23;
    vector<Component *> net;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 6, &p, &r124));
    net.push_back(new Resistor("R2", 4, &r124, &r23));
    net.push_back(new Resistor("R3", 8, &r23, &n));
    net.push_back(new Resistor("R4", 12, &r124, &n));
    Simulation simulation{};
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