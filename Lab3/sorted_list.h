#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <iostream>
using namespace std;

class Sorted_List
{

private:
    struct Node
    {
        int data{};
        Node *next{};
    };
    void insert_sort(Node *current_node, Node *temp);
    Node *first{};
    // Node *copy(Node const *n);

public:
    // Default constructor - default due to the presens of other constructors
    Sorted_List() = default;

    // Destructor
    ~Sorted_List();

    // Move constructor
    Sorted_List(Sorted_List &&original);

    // Copy oonstructor
    Sorted_List(Sorted_List const &original);

    // Copy operator
    Sorted_List &operator=(Sorted_List const &original);

    // Move operator
    Sorted_List &operator=(Sorted_List &&original);

    void insert(int const &data);
    bool is_empty() const;
    int getValueAt(int const &index) const;
    int size() const;
    void print() const;
    std::string print_test() const;
    void remove(int const &index);
    void clear_list();
    string list_string();
};

#endif