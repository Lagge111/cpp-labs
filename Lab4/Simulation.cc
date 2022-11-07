#include <iostream>
#include <string>

using namespace std;

void Simulation::simulate(vector<Component*> const net, int const iterations, int const outputRows, double const timeStep)
{
    cout << left;
    int size{static_cast<int>(net.size())};
    for (int i{0}; i < size; ++i) {
        cout << net.at(i).getName();
    }
}