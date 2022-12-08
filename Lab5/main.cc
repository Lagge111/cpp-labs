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
void count_words(vector<string> &text, map<string, int> &results, vector<pair<string, int>> &sorted_list);
bool str_compare(string a, string b);

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

    /* Add flags and corresponding functions to map */
    map<string, void (*)(vector<string> &, string)> param_func_map = {
        {"--print", print},
        {"--frequency", frequency},
        {"--table", table},
        {"--substitute", substitute},
        {"--remove", remove_word},
    };

    /* Call the function(s) corresponding to the input flags */
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
    vector<pair<string, int>> sorted_list;

    count_words(text, results, sorted_list);

    // Sorts the sorted_list by frequency
    sort(sorted_list.begin(), sorted_list.end(), [](auto &left, auto &right)
         { return left.second > right.second; });

    // Used to find the length of the longest word in the text vector
    // which is used to format the output correctly.
    // TODO: For some reason this only works with the 'cool_text.txt' text file.
    auto amazing_variable = max_element(text.begin(), text.end(), str_compare);
    auto longest_word = distance(text.begin(), amazing_variable);

    // Iterator for printing the frequency
    for (vector<pair<string, int>>::iterator it{sorted_list.begin()}; it != sorted_list.end(); ++it)
    {
        cout << setw(amazing_variable[longest_word].size()) << it->first << " " << it->second << endl;
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
    vector<pair<string, int>> sorted_list;

    count_words(text, results, sorted_list);

    // Sorts the sorted_list in lexicographical order
    sort(sorted_list.begin(), sorted_list.end(), [](auto &left, auto &right)
         { return left.first < right.first; });

    // Used to find the length of the longest word in the text vector
    // which is used to format the output correctly.
    // TODO: For some reason this only works with the 'cool_text.txt' text file.
    auto amazing_variable = max_element(text.begin(), text.end(), str_compare);
    auto longest_word = distance(text.begin(), amazing_variable);

    // Iterator for printing the table
    for (vector<pair<string, int>>::iterator it{sorted_list.begin()}; it != sorted_list.end(); ++it)
    {
        cout << it->first << setw(amazing_variable[longest_word].size() - it->first.size() + 2) << it->second << endl;
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
void count_words(vector<string> &text, map<string, int> &results, vector<pair<string, int>> &sorted_list)
{
    // Count words and add to results vector
    for_each(text.begin(), text.end(), [&results](string word)
             { results[word]++; });

    // Add words to sorted_list vector
    transform(results.begin(), results.end(), back_inserter(sorted_list), [](const pair<string, int> &p)
              { return p; });
}

/**
 * @brief Compares two strings.
 *
 * @param a The first string to compare.
 * @param b The second string to compare.
 * @return true True if a < b.
 * @return false False if a > b.
 */
bool str_compare(string a, string b)
{
    return (a.size() < b.size());
}