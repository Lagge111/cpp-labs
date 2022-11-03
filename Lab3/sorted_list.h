#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{

private:
    struct Node
    {
        int data{};
        Node *next{};
    };
    Node *first{};
    // Recursive helper function for insert
    void insert_sort(Node *current_node, Node *temp);
    // Recursive helper function for print
    void recursive_print(Node *current, std::string &str);

public:
    // Default constructor
    Sorted_List() = default;

    // Desctructor
    ~Sorted_List();

    // Move constructor
    Sorted_List(Sorted_List &&original);

    // Copy constructor
    Sorted_List(Sorted_List const &original);

    // Copy operator
    Sorted_List &operator=(Sorted_List const &original);

    // Move operator
    Sorted_List &operator=(Sorted_List &&original);

    void insert(int const &data);
    bool is_empty() const;
    int getValueAt(int const &index) const;
    int size() const;
    std::string print();
    void remove(int const &index);
    void clear_list();
    std::string list_string();
};

#endif