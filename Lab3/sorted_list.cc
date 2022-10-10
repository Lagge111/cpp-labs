#include <iostream>
#include <sstream>
#include "sorted_list.h"

using namespace std;

Sorted_List::~Sorted_List()
{
    clear_list();
}

// Copy constructor
Sorted_List::Sorted_List(Sorted_List const &original)
{
    *this = original;
    cout << "copy constructor reached" << endl; // test-kommentar
}

// Copy operator
Sorted_List &Sorted_List::operator=(Sorted_List const &original)
{
    if (original.first != nullptr)
    {
        Node *temp{original.first};
        Node *new_node{new Node{temp->data, nullptr}};
        first = new_node;
        temp = temp->next;
        while (temp != nullptr)
        {
            new_node->next = new Node{temp->data, nullptr};
            new_node = new_node->next;
            temp = temp->next;
        }
        cout << "Copy operator reached" << endl; // test-kommentar
    }
    return *this;
}

// Move operator
Sorted_List &Sorted_List::operator=(Sorted_List &&original)
{
    clear_list();
    *this = original;
    original.clear_list();
    cout << "Move operator reached" << endl; // test-kommentar
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

void Sorted_List::remove(int const &index)
{
    Node *current = first;

    if (index == 0)
    {
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

// Change name if we use this.
string Sorted_List::print_test() const
{
    if (is_empty())
    {
        return "";
    }
    Node *current = first;
    ostringstream oss;
    while (current->next != nullptr)
    {
        oss << current->data << ", ";
        current = current->next;
    }
    oss << current->data;
    return oss.str();
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

string Sorted_List::list_string()
{
    if (is_empty())
    {
        return "empty";
    }
    else
    {
        string s;
        for (int i{0}; i < size(); ++i)
        {
            s = s.append(to_string(getValueAt(i)));
        }
        return s;
    }
}