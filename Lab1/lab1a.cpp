#include <iostream>
#include <iomanip>
using namespace std;

// TODO: Complementary work: Don't repeat sticky IO manipulators.
// Every manipulator (except setw) will "stick" until a different
// manipulator overrides it, so it is unnecessary to repeat them.

// Fixed by only declaring sticky IO manipulators once. 

int main() {

    int number{};
    double f_number{};
    char character{};
    string word{};

    cout << "Enter one integer: ";
    cin >> number;
    cout << "You entered the number: " << number << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter four integers: ";
    cin >> number;
    cout << "You entered the numbers: " << number << " ";
    cin >> number;
    cout << number << " ";
    cin >> number;
    cout << number << " ";
    cin >> number;
    cout << number << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter one integer and one real number: ";
    cin >> number;
    cin >> f_number;
    cout << "The real is: " << right << setw(11) << fixed << setprecision(3) << f_number << endl;
    cout << "The integer is: " << setw(8) << number << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter one real and one integer number: ";
    cin >> f_number;
    cin >> number;
    cout << "The real is: " << setfill('.') << setw(11) << f_number << endl;
    cout << "The integer is: " << setw(8) << number << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter a character: ";
    cin >> character;
    cout << "You entered: " << character << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter a word: ";
    cin >> word;
    cout << "The word '" << word << "' has " << word.length() << " character(s)." << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter an integer and a word: ";
    cin >> number;
    cin >> word;
    cout << "You entered '" << number << "' and '" << word << "'" << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter an character and a word: ";
    cin >> character;
    cin >> word;
    cout << "You entered the string \"" << word << "\" and the character '" << character << "'" << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter a word and a real number ";
    cin >> word;
    cin >> f_number;
    cout << "You entered \"" << word << "\" and \"" << f_number << "\"." << endl;
    cin.ignore(1000, '\n');

    cout << "\nEnter a text-line: ";
    getline(cin, word);
    cout << "You entered: \"" << word << "\"" << endl;

    cout << "\nEnter a second line of text: ";
    getline(cin, word);
    cout << "You entered: \"" << word << "\"" << endl;

    cout << "\nEnter three words: ";
    cin >> word;
    cout << "You entered : '" << word << " ";
    cin >> word;
    cout << word << " ";
    cin >> word;
    cout << word;
    cout << "'" << endl;
    cin.ignore(1000, '\n');

    return 0;
}