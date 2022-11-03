#include <sstream>
#include "sorted_list.h"

using namespace std;

// Sorted_List destructor
Sorted_List::~Sorted_List()
{
    clear_list();
}

// Move constructor
Sorted_List::Sorted_List(Sorted_List &&original)
{
    *this = move(original);
}

// Copy constructor
Sorted_List::Sorted_List(Sorted_List const &original)
{
    *this = original;
}

// Copy assignment operator
Sorted_List &Sorted_List::operator=(Sorted_List const &original)
{
    if (original.first != nullptr)
    {
        Node *original_node{original.first};
        Node *copied_node{new Node{original_node->data, nullptr}};

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

// Move assignment operator
Sorted_List &Sorted_List::operator=(Sorted_List &&original)
{
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
    Node *current{first};

    if (index == 0)
    {
        first = current->next;
        delete current;
    }
    else
    {
        Node *previous{first};
        for (int i{0}; i < size(); ++i)
        {
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

void Sorted_List::recursive_print(Node *current, string &str)
{
    str.append(to_string(current->data));
    if (current->next == nullptr)
    {
        return;
    }
    str.append(" -> ");
    recursive_print(current->next, str);
}

int Sorted_List::getValueAt(int const &index) const
{
    if (!is_empty())
    {
        Node *tmp{first};
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
