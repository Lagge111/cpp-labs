
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
        - 'parameter' which is everything to the right of the '='. If no '=' was found, then this string is empty.
    c) Determine which operation the 'flag' corresponds to and perform this operation.
        - It is ok to do use if-else-if structure for this.

5. Once all flags have been processed the program is done.
------------------------------------------------------------------------------------- */

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
        cout << "Invalid number of arguments. Enter arguments in the format: ./a.out [file_name] [flag]" << endl;
        cout << "List of valid flags:\n--print\n--frequency\n--table\n--substitute=<old>+<new>\n--remove=<word>" << endl;
        return 1;
    }

    /* Open the specified file */
    ifstream infile{};
    infile.open(argv[1]);

    /* Place remaining arguments into a vector */
    vector<string> arguments(argv + 2, argv + argc);

    /* Read words from the file into a vector */
    vector<string> text((istream_iterator<string>(infile)), istream_iterator<string>());

    /* Split arguments into flag and parameter */
    map<string, string> flags_and_parameters{};

    /* Add flags and corresponding functions to map */
    // TODO: Add reference to vector<string>
    map<string, void (*)(vector<string> &, string)> param_func_map = {
        {"--print", print},
        {"--frequency", frequency},
        {"--table", table},
        {"--remove", remove_word},
        {"--substitute", substitute},
    };

    if (arguments.size() > 0)
    {
        for (vector<string>::iterator it{arguments.begin()}; it != arguments.end(); ++it)
        {
            string argument{*it};
            param_func_map[argument.substr(0, argument.find("="))](text, argument.substr(argument.find("=") + 1));
        }
    }
}

/**
 * @brief Prints all the words in the text vector.
 *
 * @param text The vector containing the words from the file.
 */
void print(vector<string> &text, string /* parameter */)
{
    for (vector<string>::iterator it{text.begin()}; it != text.end(); ++it)
    {
        cout << *it << " ";
    }
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
    vector<pair<string, int>> sorted_list;
    count_words(text, results);

    // Adds the results to the sorted_list
    for (map<string, int>::iterator it{results.begin()}; it != results.end(); ++it)
    {
        sorted_list.push_back(*it);
    }

    // Sorts the sorted_list by frequency
    sort(sorted_list.begin(), sorted_list.end(), [](auto &left, auto &right)
         { return left.second > right.second; });

    // Iterator for printing the frequency
    for (vector<pair<string, int>>::iterator it{sorted_list.begin()}; it != sorted_list.end(); ++it)
    {
        cout << setw(11) << it->first << " " << it->second << endl;
    }
}

/**
 * @brief Counts the frequency of each word in the text vector.
 *
 * @param text The vector containing the words from the file.
 * @param results The map used for pairing a word with its frequency.
 */
void count_words(vector<string> &text, map<string, int> &results)
{
    for_each(text.begin(), text.end(), [&results](string word)
             { results[word]++; });
}

/**
 * @brief Prints a frequency table where the words are sorted in lexicographical order.
 *
 * @param text The vector containing the words from the file.
 */
void table(vector<string> &text, string /* parameter */)
{
    map<string, int> results;
    vector<pair<string, int>> sorted_list;
    count_words(text, results);

    // Adds the results calculated in count_words to the sorted_list
    for_each(results.begin(), results.end(), [&sorted_list](auto &word)
             { sorted_list.push_back(word); });

    // Sorts the sorted_list in lexicographical order
    sort(sorted_list.begin(), sorted_list.end(), [](auto &left, auto &right)
         { return left.first < right.first; });

    // Iterator for printing the table
    // Formatting is wrong
    for (vector<pair<string, int>>::iterator it{sorted_list.begin()}; it != sorted_list.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
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
    string old_word{};
    string new_word{};
    bool reached{false};

    // Separates the old word and the new word from the parameter
    for_each(parameter.begin(), parameter.end(), [&reached, &old_word, &new_word](char c)
             {
                if (c == '+') {
                    reached = true;
                } else if (!reached) {
                    old_word.push_back(c);
                } else {
                    new_word.push_back(c);
                } });

    /* This should work, but doesn't for some reason */
    // for_each(parameter.begin(), parameter.end(), [&reached, &old_word, &new_word](char c)
    //          { c == '+'   ? reached = true
    //            : !reached ? old_word.push_back(c)
    //                       : new_word.push_back(c); });

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
