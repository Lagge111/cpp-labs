#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List {

private:
    struct Node {
        int data{};
        Node* next{};
    };
    void insert_sort(Node* current_node, Node* temp);
    Node* first{};

public:
    void insert(int const &value);
    bool is_empty() const;
    int getValueAt(int const &index) const; 
    int size() const;
    void print() const;
    void remove(int const &index);
};

// struct Node {
//     int data{};
//     Node* next{};
// };

#endif