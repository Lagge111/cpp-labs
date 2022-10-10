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
    // Default constructor
    Sorted_List() = default;

    // Destructor
    ~Sorted_List();

    // Copy constructur
    Sorted_List(Sorted_List const &original);

    // Move constructor
    Sorted_List(Sorted_List &&other);

    // Copy assignment operator
    Sorted_List &operator=(Sorted_List const &other);

    // Move assignment operator
    Sorted_List &operator=(Sorted_List &&other);

    /*
        //Destructor
        ~Sorted_List() {
            Node* current = first;
            Node* next;

            while (current != NULL) {
                next = current->next;
                delete current;
                current = next;
            }

            cout << "destructor executed" << endl;
        }

        //Copy constructor
        Sorted_List(Sorted_List const& original) {
            cout << "hej" << endl;
        }

        //Move constructor
        Sorted_List(Sorted_List&& other) {

        }*/

    void insert(int const &value);
    bool is_empty() const;
    int getValueAt(int const &index) const;
    int size() const;
    void print() const;
    void remove(int const &index);
    void clear_list();
};

#endif