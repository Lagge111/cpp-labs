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
void find_longest_word(vector<string> &text, vector<string>::iterator &longest_word);
vector<pair<string, int>> get_frequency(vector<string> &text);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "Invalid number of arguments. Arguments should follow the format: ./a.out [file_name] [flag]" << endl;
        return 1;
    }

    /* Open the specified input file */
    ifstream infile{};
    infile.open(argv[1]);

    /* Place remaining arguments in a vector */
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

    /* Read words from the input file into a vector */
    vector<string> text((istream_iterator<string>(infile)), istream_iterator<string>());

    /* Call the function(s) corresponding to the input flags */
    for (vector<string>::iterator it{arguments.begin()}; it != arguments.end(); ++it)
    {
        string argument{*it};
        func_map[argument.substr(0, argument.find("="))](text, argument.substr(argument.find("=") + 1));
    }
}

void print(vector<string> &text, string /* parameter */)
{
    copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

void frequency(vector<string> &text, string /* parameter */)
{
    vector<string>::iterator longest_word{};
    vector<pair<string, int>> frequency_list{get_frequency(text)};

    sort(frequency_list.begin(), frequency_list.end(), [](pair<string, int> &left, pair<string, int> &right)
         { return left.second > right.second; });

    find_longest_word(text, longest_word);

    for (vector<pair<string, int>>::iterator it{frequency_list.begin()}; it != frequency_list.end(); ++it)
    {
        cout << setw(longest_word->size()) << it->first << " " << it->second << endl;
    }
}

void table(vector<string> &text, string /* parameter */)
{
    vector<string>::iterator longest_word{};
    vector<pair<string, int>> frequency_list{get_frequency(text)};

    sort(frequency_list.begin(), frequency_list.end());

    find_longest_word(text, longest_word);

    for (vector<pair<string, int>>::iterator it{frequency_list.begin()}; it != frequency_list.end(); ++it)
    {
        cout << it->first << setw(longest_word->size() - it->first.size() + 2) << it->second << endl;
    }
}

void substitute(vector<string> &text, string parameter)
{
    string old_word(parameter.substr(0, parameter.find('+')));
    string new_word(parameter.substr(parameter.find('+') + 1));
    replace(text.begin(), text.end(), old_word, new_word);
}

void remove_word(vector<string> &text, string parameter)
{
    text.erase(remove(text.begin(), text.end(), parameter), text.end());
}

/* HELPER FUNCTIONS */

void find_longest_word(vector<string> &text, vector<string>::iterator &longest_word)
{
    longest_word = max_element(text.begin(), text.end(), [](string &a, string &b)
                               { return a.size() < b.size(); });
}

vector<pair<string, int>> get_frequency(vector<string> &text)
{
    map<string, int> results{};
    for (vector<string>::iterator it{text.begin()}; it != text.end(); ++it)
    {
        results[*it]++;
    }
    vector<pair<string, int>> frequency_list(results.begin(), results.end());

    return frequency_list;
}