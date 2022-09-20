#include <iostream>
#include "sorted_list.h"

using namespace std;

Node* first{};

void Sorted_List::insert(int const &value) {
    Node* tmp{new Node{value}};
    tmp->next = first;
    first = tmp;
    

}

void Sorted_List::remove() {

}

void Sorted_List::print() {
    if (!is_empty()) {
        Node* tmp = first;
        for (int i{0}; i < size(); ++i) {
            cout << tmp->data << " <- ";
            tmp = tmp->next;
        }
    } else {
        cout << "The list is empty." << endl;
    }
}

int Sorted_List::getValueAt(int const &index) {
    if (!is_empty()) {
        Node* tmp = first;
        for (int i{size()}; i > (index + 1); --i) {
            tmp = tmp->next;
        }
        return tmp->data;
    }
}

int Sorted_List::size() {
    Node* tmp = first;
    int size{0};
    while (tmp != NULL) {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

bool Sorted_List::is_empty() {
    return first == NULL;
}
