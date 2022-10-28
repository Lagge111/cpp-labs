#include <iostream>
#include <sstream>
#include "sorted_list.h"

using namespace std;

// Sorted_List destructor
Sorted_List::~Sorted_List()
{
    clear_list();
}

Sorted_List::Sorted_List(Sorted_List &&original)
{
    *this = move(original);
}

// Copy constructor
Sorted_List::Sorted_List(Sorted_List const &original)
{
    *this = original;
}

// Copy operator
Sorted_List &Sorted_List::operator=(Sorted_List const &original)
{
   if (original.first != nullptr)
    {
        // *original_node points at the value from the original list, so we can "get" the value
        // *copied_node points at a new node which acts as a copy, with values from the "getter" original_node
        Node *original_node{original.first};
        Node *copied_node{new Node{original_node->data, nullptr}};
        
        //copy lists first node gets the first value from the original list
        //we change the original_node to the next one in the original list, even if its NULL
        first = copied_node;
        original_node = original_node->next;

        while (original_node != nullptr)
        {
            copied_node->next = new Node{original_node->data, nullptr};
            copied_node = copied_node->next;
            original_node = original_node->next;
        }
    }
    return *this;
}

// Move operator
Sorted_List &Sorted_List::operator=(Sorted_List &&original)
{
    clear_list();
    *this = original;
    original.clear_list();
    return *this;
}

// Clear list of nodes
void Sorted_List::clear_list()
{
    while (!is_empty())
    {
        remove(0);
    }
}

void Sorted_List::insert(int const &data)
{

    Node *new_node{new Node{data, nullptr}};

    //if empty
    if (first == nullptr)
    {
        first = new_node;
    }
    //if new_node data is lower than the first node data, assign the new_node as first
    else if (data < first->data)
    {
        new_node->next = first;
        first = new_node;
    }
    //find correct position
    else
    {
        insert_sort(first, new_node);
    }
}

void Sorted_List::insert_sort(Node *current_node, Node *new_node)
{
    //if the current_node is the last, connect the new_node as the last node in list
    if (current_node->next == nullptr)
    {
        current_node->next = new_node;
        new_node->next = nullptr;
        return;
    }
    
    Node *next_node{current_node->next};
    //if the upcoming nodes data is higher, then should new_node be between current and currents next
    //current_node -> new_node -> next_node
    //can't use next_node = new_node, because then we cant use the "primary" next_node for new_node->next = next_node
    if (new_node->data <= next_node->data)
    {
        current_node->next = new_node;
        new_node->next = next_node;
        return;
    }
    //keep searching
    else
    {
        insert_sort(next_node, new_node);
    }
}

void Sorted_List::remove(int const &index)
{
    Node *current{first};

    //if the we are removing first, delete and replace it with second node as first
    if (index == 0)
    {
        first = current->next;
        delete current;
    }
    else
    {
        Node*previous{first};
        for (int i{0}; i < size(); ++i)
        {
            //if correct index, connect the previous and the next together, then remove current
            //previous -> [deleted current] -> current.next
            if (i == index)
            {
                previous->next = current->next;
                delete current;
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }
}

string Sorted_List::print()
{
    string str{};

    if (is_empty())
    {
        return "";
    }

    recursive_print(first, str);
    return str;
}

void Sorted_List::recursive_print(Node* current, string &str)
{
    str.append(to_string(current->data));
    if (current->next == nullptr) {
        return;
    } 
    str.append(" -> ");
    recursive_print(current->next, str);
}

int Sorted_List::getValueAt(int const &index) const
{
    if (!is_empty())
    {
        Node *tmp = first;
        for (int i{0}; i < index; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    return 0;
}

int Sorted_List::size() const
{
    Node *tmp{first};
    int size{0};
    while (tmp != nullptr)
    {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

bool Sorted_List::is_empty() const
{
    return first == nullptr;
}
