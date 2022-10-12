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
    Node *first{};
    void insert_sort(Node *current_node, Node *temp);
    void recursive_print(Node* current, string &str);

public:
    Sorted_List() = default;

    ~Sorted_List();

    Sorted_List(Sorted_List &&original);

    Sorted_List(Sorted_List const &original);

    Sorted_List &operator=(Sorted_List const &original);

    Sorted_List &operator=(Sorted_List &&original);

    void insert(int const &data);
    bool is_empty() const;
    int getValueAt(int const &index) const;
    int size() const;
    string print();
    void remove(int const &index);
    void clear_list();
    string list_string();
};

#endif