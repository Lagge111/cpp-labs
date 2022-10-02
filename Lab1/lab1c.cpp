#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int word_count{};
    int char_count{};
    string shortest_word{};
    string longest_word{};
    string current_word{};

    ifstream input_file{"data.txt"};

    if (!input_file)
    {
        cerr << "ERROR: Input file not found." << endl;
        return 0;
    }

    input_file >> longest_word;
    shortest_word = longest_word;
    word_count++;
    char_count = longest_word.length();

    while (input_file >> current_word)
    {
        char_count += current_word.length();
        word_count++;

        if (current_word.length() <= shortest_word.length())
        {
            shortest_word = current_word;
        }
        else if (current_word.length() >= longest_word.length())
        {
            longest_word = current_word;
        }
    }

    if (word_count == 0)
    {
        cerr << "ERROR: Input file is empty." << endl;
        return 0;
    }

    cout << "There are " << word_count << " words in the file." << endl;
    cout << "The shortest word was \"" << shortest_word << "\" with " << shortest_word.length() << " character(s)." << endl;
    cout << "The longest word was \"" << longest_word << "\" with " << longest_word.length() << " character(s)." << endl;
    cout << "The average length was " << fixed << setprecision(2) << static_cast<double>(char_count) / word_count << " character(s)." << endl;

    input_file.close();

    return 0;
}
