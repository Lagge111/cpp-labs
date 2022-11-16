#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Simulation.h"
#include <iostream>
#include <string>

using namespace std;

void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_2(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_3(int const iterations, int const outputRows, double const timeStep, double const voltage);
void deallocate_components(vector<Component *> v);

int main(int argc, char **argv)
{
    if (argc == 5)
    {
        try
        {
            int iterations{stoi(argv[1])};
            int outputRows{stoi(argv[2])};
            double timeStep{stod(argv[3])};
            double voltage{stod(argv[4])};

            circuit_1(iterations, outputRows, timeStep, voltage);
            circuit_2(iterations, outputRows, timeStep, voltage);
            circuit_3(iterations, outputRows, timeStep, voltage);
        }
        catch (invalid_argument &e)
        {
            cout << "Invalid argument(s). Arguments should follow the format 'int' (iterations) 'int' (printed lines) 'double' (time step) 'double' (voltage)." << endl;
        }
    }
    else
    {
        cout << "Invalid number of arguments. Please include four (4) arguments." << endl;
        return 1;
    }
}

void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, r124, r23;
    vector<Component *> circuit;
    circuit.push_back(new Battery("Bat", voltage, &p, &n));
    circuit.push_back(new Resistor("R1", 6, &p, &r124));
    circuit.push_back(new Resistor("R2", 4, &r124, &r23));
    circuit.push_back(new Resistor("R3", 8, &r23, &n));
    circuit.push_back(new Resistor("R4", 12, &r124, &n));
    Simulation simulation{};
    simulation.simulate(circuit, iterations, outputRows, timeStep);
    deallocate_components(circuit);
}

void circuit_2(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, l, r;
    vector<Component *> circuit;
    circuit.push_back(new Battery("Bat", voltage, &p, &n));
    circuit.push_back(new Resistor("R1", 150, &p, &l));
    circuit.push_back(new Resistor("R2", 50, &p, &r));
    circuit.push_back(new Resistor("R3", 100, &l, &r));
    circuit.push_back(new Resistor("R4", 300, &l, &n));
    circuit.push_back(new Resistor("R5", 250, &r, &n));
    Simulation simulation{};
    simulation.simulate(circuit, iterations, outputRows, timeStep);
    deallocate_components(circuit);
}

void circuit_3(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, l, r;
    vector<Component *> circuit;
    circuit.push_back(new Battery("Bat", voltage, &p, &n));
    circuit.push_back(new Resistor("R1", 150, &p, &l));
    circuit.push_back(new Resistor("R2", 50, &p, &r));
    circuit.push_back(new Capacitor("C3", 1.0, &l, &r));
    circuit.push_back(new Resistor("R4", 300, &l, &n));
    circuit.push_back(new Capacitor("C5", 0.75, &r, &n));
    Simulation simulation{};
    simulation.simulate(circuit, iterations, outputRows, timeStep);
    deallocate_components(circuit);
}

void deallocate_components(vector<Component *> circuit)
{
    for (Component *component : circuit)
    {
        delete component;
    }
    circuit.clear();
}
