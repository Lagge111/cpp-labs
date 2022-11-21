
/* WHAT THE PROGRAM SHOULD DO */
/* ----------------------------------------------------------------------------------
1. Open the file specified in the first command line argument.

2. Place the remaining arguments in a container (list, vector, etc.).
    a) The first two arguments should not be placed in this container, i.e. not ./a.out and the specified file name.
    b) Important to keep the order of the arguments.

3. Read all words from the file that was specified into a container called text.

4. For each argument in the argument container (from step 2):
    a) Find the first occurance of the character '=' (if it exists).
    b) Split the argument into two parts:
        - 'flag' which is everything to left of the '='. If no '=' was found, flag is equal to the argument (flag = argument).
        - 'parameter' which is everything to the right of the '='. If no '=' was found, the this string is empty.
    c) Determine which operation the 'flag' corresponds to and perform this operation.
        - It is ok to do use if-else-if structure for this.

5. Once all flags have been processed the program is done.
------------------------------------------------------------------------------------- */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

ifstream infile{};
vector<string> arguments{};

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Too few arguments." << endl;
        return 1;
    }

    // Open the file in the first command line argument.
    infile.open(argv[1]);

    // Add remaining arguments to a vector.
    for (int i{2}; i <= argc; ++i)
    {
        arguments.push_back(argv[i]);
    };

    // Read all words from the file into a vector.
    vector<string> text((istream_iterator<string>(infile)), istream_iterator<string>());

    // Find first occurance of '=' character in arguments vector
    // 'find()' returns the index where '=' is found. Not sure what to do with this now.
    int test = arguments[2].find('=');

    // Something else happens here...

    // If the flag is --print
    // Print all words in 'text' vector, using print() help function.
    for_each(text.begin(), text.end(), [&](string currentWord)
             { print(currentWord); });

    // Something else happens here...
}

void print(string word)
{
    cout << word << " ";
}