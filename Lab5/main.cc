
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
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;

vector<string> arguments{};
ifstream infile{};
void print(vector<string> text);
void frequency(vector<string> text);
bool cmp(pair<string, int>& a, pair<string, int>&b);
bool cmp2(pair<string, int>& a, pair<string, int>&b);
void table(vector<string> text);
void substitute(vector<string> text, string parameter);
void remove(vector<string> text, string parameter);
void count_words(vector<string> &text, map<string, int> &results);

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
    if (argc > 2) {
        arguments.push_back(argv[2]);
    }

    // for_each(argv[2], argv[argc - 1], [&arguments](string argument) {
    //     arguments.push_back(argument);
    // });

    // Read all words from the file into a vector.
    vector<string> text((istream_iterator<string>(infile)), istream_iterator<string>());

    for (string word : text) {
        cout << word << " ";
    }

    string flag{};
    string parameter{};
    bool reached{false};
    
    if (argc > 2) {
        for (char c : arguments[0]) {
            if (c == '=') {
                reached = true;
            } else if (!reached) {
                flag.push_back(c);
            } else {
                parameter.push_back(c);
            }
        }
    }
    cout << endl;
    cout << flag << endl;
    cout << parameter << endl;
    cout << "something" << endl;

    if (flag == "--print") {
        print(text);
    } else if (flag == "--frequency") {
        frequency(text);
    } else if (flag == "--table") {
        table(text);
    } else if (flag == "--substitute") {
        substitute(text, parameter);
    } else if (flag == "--remove") {
        remove(text, parameter);
    }
    cout << endl;
}

void print(vector<string> text)
{
    for (string word : text) {
        cout << word << " ";
    }
}

void frequency(vector<string> text) 
{
    map<string, int> results;

    count_words(text, results);

    // sort
    vector<pair<string, int> > sorted_list;

    for (auto& it : results) {
        sorted_list.push_back(it);
    }

    sort(sorted_list.begin(), sorted_list.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    for (auto& it : sorted_list) {
        cout << it.first << ' ' << it.second << endl;
    }
}
  
void count_words(vector<string> &text, map<string, int> &results) {
for_each(text.begin(), text.end(), [&results](string word)
    {
        if(results.count(word)) { 
            results[word]++;
        } else {
            results.insert({word, 1});
        }
        //results.count(word) ? results[word]++ : results.insert({word, 1});
    });
}


void table(vector<string> text) {
    map<string, int> results;

    //hur många gånger ett ord förekommer
    count_words(text, results);

    vector<pair<string, int> > sorted_list;

    for_each(results.begin(), results.end(), [&sorted_list](auto& word) {
        sorted_list.push_back(word);
    });

    sort(sorted_list.begin(), sorted_list.end(), [](auto &left, auto &right) {
        return left.first < right.first;
    });

    for (auto& it : sorted_list) {
        cout << it.first << ' ' << it.second << endl;
    }
}

void substitute(vector<string> text, string parameter)
{
    string old_word{};
    string new_word{};
    bool reached{false};

    for (char c : parameter) {
        if (c == '+') {
            reached = true;
        } else if (!reached) {
            old_word.push_back(c);
        } else {
            new_word.push_back(c);
        }
    }

    std::replace(text.begin(), text.end(), old_word, new_word);

    print(text);
}

void remove(vector<string> text, string parameter)
{
    text.erase(std::remove(text.begin(), text.end(), parameter), text.end());
}
