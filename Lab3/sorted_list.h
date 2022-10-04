#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <iostream>
using namespace std;

class Sorted_List {

private:

    struct Node {
        int data{};
        Node* next{};
    };
    void insert_sort(Node* current_node, Node* temp);
    Node* first{};

public:
    //Default constructor
    Sorted_List() {

    }

    //Destructor
    ~Sorted_List() {

    }

    //Copy constructor
    Sorted_List(Sorted_List const& original) {
        cout << "hej" << endl;
    }

    //Move constructor
    Sorted_List(Sorted_List&& other) {

    }

    void insert(int const &value);
    bool is_empty() const;
    int getValueAt(int const &index) const; 
    int size() const;
    void print() const;
    void remove(int const &index);
};

#endif