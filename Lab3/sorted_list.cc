#include <iostream>
#include "sorted_list.h"

using namespace std;

Sorted_List::~Sorted_List() {
    while (!is_empty()) {
        remove(0);
    }
}

// Move constructor
    Sorted_List::Sorted_List(Sorted_List &&other)
{
    other.first = nullptr;
}

// Copy constructor
Sorted_List::Sorted_List(Sorted_List const &other)
{
    if (other.first != nullptr)
    {
        Node *temp{other.first};
        Node *new_node{new Node{temp->data, nullptr}};
        first = new_node;
        temp = temp->next;
        while (temp != nullptr)
        {
            new_node->next = new Node{temp->data, nullptr};
            new_node = new_node->next;
            temp = temp->next;
        }
    }
}


void Sorted_List::insert(int const &data) {
    
    Node* new_node{new Node{data, nullptr}};
}



/*// Copy assignment operator
Sorted_List &Sorted_List::operator=(Sorted_List const &other)
{
    Sorted_List tmp{other};
    std::swap(first, tmp.first);
    return *this;
}

// Move assignment operator
Sorted_List &Sorted_List::operator=(Sorted_List &&other)
{
    clear_list();
    first = other.first;
    other.first = nullptr;
    return *this;
}*/

// Clear list of nodes
void Sorted_List::clear_list()
{
    while (first != nullptr)
    {
        remove(first->data);
    }
}

void Sorted_List::insert(int const &data)
{

    Node *new_node{new Node{data, nullptr}};

    if (first == nullptr)
    {
        first = new_node;
    }
    else if (data < first->data)
    {
        new_node->next = first;
        first = new_node;
    }
    else
    {
        insert_sort(first, new_node);
    }
}

void Sorted_List::insert_sort(Node *current_node, Node *new_node)
{
    if (current_node->next == nullptr)
    {
        current_node->next = new_node;
        new_node->next = nullptr;
        return;
    }
    Node *next_node{current_node->next};
    if (new_node->data <= next_node->data)
    {
        current_node->next = new_node;
        new_node->next = next_node;
        return;
    }
    else
    {
        insert_sort(next_node, new_node);
    }
}

void Sorted_List::remove(int const &index) {
    Node* current = first;
    

    if (index == 0) {
        first = current->next;
        delete current;
    }
    else
    {
        Node *last = first;
        for (int i{0}; i < size(); ++i)
        {
            if (i == index)
            {
                last->next = current->next;
                delete current;
                break;
            }
            else
            {
                last = current;
                current = current->next;
            }
        }
    }
}

void Sorted_List::print() const
{
    if (!is_empty())
    {
        Node *tmp = first;
        for (int i{0}; i < size(); ++i)
        {
            cout << tmp->data;
            if (i != size() - 1)
            {
                cout << " -> ";
            }
            tmp = tmp->next;
        }
        cout << endl;
    }
    else
    {
        cout << "The list is empty." << endl;
    }
}

int Sorted_List::getValueAt(int const &index) const
{
    if (!is_empty())
    {
        Node *tmp = first;
        for (int i{size()}; i > (index + 1); --i)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    return 0;
}

int Sorted_List::size() const
{
    Node *tmp = first;
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
