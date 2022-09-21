#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List {
    public:
    void insert(int const &value);
    bool is_empty();
    int getValueAt(int const &index); 
    int size();
    void print();
    void remove(int const &index);
};

struct Node {
    int data{};
    Node* next{};
};

#endif