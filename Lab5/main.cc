#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;

void print(vector<string> &text, string /* parameter */);
void frequency(vector<string> &text, string /* parameter */);
void table(vector<string> &text, string /* parameter */);
void substitute(vector<string> &text, string parameter);
void remove_word(vector<string> &text, string parameter);
void count_words(vector<string> &text, map<string, int> &results);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "Invalid number of arguments. Arguments should follow the format: ./a.out [file_name] [flag]" << endl;
        return 1;
    }

    /* Open the specified file */
    ifstream infile{};
    infile.open(argv[1]);

    /* Place remaining arguments into a vector */
    vector<string> arguments(argv + 2, argv + argc);

    /* Add flags and corresponding functions to a map */
    map<string, void (*)(vector<string> &, string)> func_map = {
        {"--print", print},
        {"--frequency", frequency},
        {"--table", table},
        {"--substitute", substitute},
        {"--remove", remove_word},
    };

    /* Check if the input flags are valid */
    for (vector<string>::iterator it{arguments.begin()}; it != arguments.end(); ++it)
    {
        string argument{*it};
        if (func_map.count(argument.substr(0, argument.find('='))) == 0)
        {
            cerr << "Invalid flag(s).\nList of valid flags:\n--print\n--frequency\n--table\n--substitute=<old>+<new>\n--remove=<word>" << endl;
            return 1;
        }
    }

    /* Read words from the file into a vector */
    vector<string> text((istream_iterator<string>(infile)), istream_iterator<string>());

    /* Call the function(s) corresponding to the input flags */
    for (vector<string>::iterator it{arguments.begin()}; it != arguments.end(); ++it)
    {
        string argument{*it};
        func_map[argument.substr(0, argument.find("="))](text, argument.substr(argument.find("=") + 1));
    }
}

/**
 * @brief Prints all the words in the text vector.
 *
 * @param text The vector containing the words from the file.
 */
void print(vector<string> &text, string /* parameter */)
{
    copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

/**
 * @brief Prints a frequency table where the words are sorted in decreasing order on the number of occurences.
 *
 * @param text The vector containing the words from the file.
 */
void frequency(vector<string> &text, string /* parameter */)
{
    map<string, int> results;

    count_words(text, results);

    vector<pair<string, int>> frequency_list(results.begin(), results.end());

    sort(frequency_list.begin(), frequency_list.end(), [](pair<string, int> &left, pair<string, int> &right)
         { return left.second > right.second; });

    // TODO: Add correct formatting by using setw(x) where x == length of the longest word.
    for (vector<pair<string, int>>::iterator it{frequency_list.begin()}; it != frequency_list.end(); ++it)
    {
        cout << setw(11) << it->first << " " << it->second << endl;
    }
}

/**
 * @brief Prints a frequency table where the words are sorted in lexicographical order.
 *
 * @param text The vector containing the words from the file.
 */
void table(vector<string> &text, string /* parameter */)
{
    map<string, int> results;

    count_words(text, results);

    vector<pair<string, int>> frequency_list(results.begin(), results.end());

    sort(frequency_list.begin(), frequency_list.end(), [](pair<string, int> &left, pair<string, int> &right)
         { return left.first < right.first; });

    // TODO: Add correct formatting by using setw(x) where x == length of the longest word - length of the current word.
    for (vector<pair<string, int>>::iterator it{frequency_list.begin()}; it != frequency_list.end(); ++it)
    {
        cout << it->first << setw(3) << it->second << endl;
    }
}

/**
 * @brief Replaces all occurences of a selected word in the text vector with a new selected word.
 *
 * @param text The vector containing the words from the file.
 * @param parameter The parameter containing the word to replace and the word to replace it with.
 */
void substitute(vector<string> &text, string parameter)
{
    string old_word(parameter.substr(0, parameter.find('+')));
    string new_word(parameter.substr(parameter.find('+') + 1));
    replace(text.begin(), text.end(), old_word, new_word);
}

/**
 * @brief Removes all occurences of a selected word.
 *
 * @param text The vector containing the words from the file.
 * @param parameter The parameter containing the word to remove.
 */
void remove_word(vector<string> &text, string parameter)
{
    text.erase(remove(text.begin(), text.end(), parameter), text.end());
}

/* HELPER FUNCTIONS */

/**
 * @brief Counts the frequency of each word in the text vector. Used in functions frequency and table.
 *
 * @param text The vector containing the words from the file.
 * @param results The map used for pairing a word with its frequency.
 * @param sorted_list The vector used to store the word-frequency pairs in order.
 */
void count_words(vector<string> &text, map<string, int> &results)
{
    for_each(text.begin(), text.end(), [&results](string word)
             { results[word]++; });
}