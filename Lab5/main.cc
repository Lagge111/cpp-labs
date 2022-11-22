
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

ifstream infile{};
vector<string> arguments{};
void print(vector<string> text);
void frequency(vector<string> text);
bool cmp(pair<string, int>& a, pair<string, int>&b);
bool cmp2(pair<string, int>& a, pair<string, int>&b);
void table(vector<string> text);
void substitute(vector<string> text, string parameter);
void remove(vector<string> text, string parameter);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Too few arguments." << endl;
        return 1;
    }

    // Open the file in the first command line argument.
    infile.open(argv[1]);
    cout << "open the file" << endl;

    // Add remaining arguments to a vector.
    if (argc > 2) {
        arguments.push_back(argv[2]);
        // for (int i{2}; i <= argc; ++i)
        // {
        //     arguments.push_back(argv[i]);
        //     cout << argv[i];
        // };
    }
    cout << "add to arguments vector" << endl;

    // Read all words from the file into a vector.
    vector<string> text((istream_iterator<string>(infile)), istream_iterator<string>());
    cout << "ŕead text file" << endl;

    for (string word : text) {
        cout << word << " ";
    }
    cout << "print text file" << endl;

    // Find first occurance of '=' character in arguments vector
    // 'find()' returns the index where '=' is found. Not sure what to do with this now.

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
}

void print(vector<string> text)
{
    for (string word : text) {
        cout << word << " ";
    }
}

void frequency(vector<string> text) 
{
    int temp;
    map<string, int> results;
    for (string word : text) {
        if (results.count(word) > 0) {
            temp = results[word];
            ++temp;
            results[word] = temp;
        } else {
            results.insert({word, 1});
        }
    }

    // sort
    vector<pair<string, int> > A;

    for (auto& it : results) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);

    for (auto& it : A) {
        cout << it.first << ' ' << it.second << endl;
    }


}

bool cmp(pair<string, int>& a, pair<string, int>&b) {
    return a.second > b.second;
}

bool cmp2(pair<string, int>& a, pair<string, int>&b) {
    return a.first < b.first;
}   

void table(vector<string> text) {
    int temp;
    map<string, int> results;
    for (string word : text) {
        if (results.count(word) > 0) {
            temp = results[word];
            ++temp;
            results[word] = temp;
        } else {
            results.insert({word, 1});
        }
    }

    vector<pair<string, int> > A;

    for (auto& it : results) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp2);

    for (auto& it : A) {
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
    cout << old_word << endl;
    cout << new_word << endl;

    for (int i{0}; i < text.size(); ++i ) {
        if (text[i] == old_word) {
            text [i] = new_word;
        } 
    }

    print(text);
}

void remove(vector<string> text, string parameter)
{
    for (string word : text) {
        if (word == parameter) {
            
        }
    }
}