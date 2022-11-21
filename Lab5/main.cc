#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream infile{};

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        infile.open(argv[1]);
    }
}