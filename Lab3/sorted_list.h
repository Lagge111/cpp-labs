#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List {

private:
    /* Construct the node inside the list class, according to Stack Overflow */ 
    struct Node {
        int data{};
        Node* next{};
    };
    /*  Can be private since we only use it as a helper function,
        which means it doesn't have to be accessible to the programmer. 
     */
    void insert_sort(Node* current_node, Node* temp);
    /*  Create the first node inside the list class because we have 
        the node struct inside the class. 
     */
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