#include <iostream>
#include <string>

#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Simulation.h"

using namespace std;

void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_2(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_3(int const iterations, int const outputRows, double const timeStep, double const voltage);
void deallocate_components(vector<Component *> v);

int main(int argc, char **argv)
{
    if (argc == 5) {
        try {
            int iterations{stoi(argv[1])};
            int outputRows{stoi(argv[2])};
            double timeStep{stod(argv[3])};
            double voltage{stod(argv[4])};

            circuit_1(iterations, outputRows, timeStep, voltage);
            circuit_2(iterations, outputRows, timeStep, voltage);
            circuit_3(iterations, outputRows, timeStep, voltage);

        } catch (invalid_argument& e) {
            cout << "Invalid argument type. Arguments should follow the format 'int int double double'." << endl;
        }
    } else {
        cout << "Invalid number of arguments." << endl;
        return 1;
    }
}

void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, r124, r23;
    vector<Component*> net;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 6, &p, &r124));
    net.push_back(new Resistor("R2", 4, &r124, &r23));
    net.push_back(new Resistor("R3", 8, &r23, &n));
    net.push_back(new Resistor("R4", 12, &r124, &n));
    Simulation simulation{};
    simulation.simulate(net, iterations, outputRows, timeStep);
    deallocate_components(net);
}

void circuit_2(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, l, r;
    vector<Component*> net;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 150, &p, &l));
    net.push_back(new Resistor("R2", 50, &p, &r));
    net.push_back(new Resistor("R3", 100, &l, &r));
    net.push_back(new Resistor("R4", 300, &l, &n));
    net.push_back(new Resistor("R5", 250, &r, &n));
    Simulation simulation{};
    simulation.simulate(net, iterations, outputRows, timeStep);
    deallocate_components(net);
}

void circuit_3(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, l, r;
    vector<Component*> net;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 150, &p, &l));
    net.push_back(new Resistor("R2", 50, &p, &r));
    net.push_back(new Capacitor("C3", 1.0, &l, &r));
    net.push_back(new Resistor("R4", 300, &l, &n));
    net.push_back(new Capacitor("C5", 0.75, &r, &n));
    Simulation simulation{};
    simulation.simulate(net, iterations, outputRows, timeStep);
    deallocate_components(net);
}

void deallocate_components(std::vector<Component *> net)
{
    for (Component *element : net)
    {
        delete element;
    }
    net.clear();
}
