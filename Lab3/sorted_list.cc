#include <iostream>
#include "sorted_list.h"

using namespace std;

//Node* first{};

void Sorted_List::insert(int const &data) {
    
    // Node* new_node{new Node{value}};
    // Node* tmp{};

    /* ======== Test ======== */
    
    Node* temp{new Node{data, nullptr}};

    /* If the list is empty. */
    if (first == nullptr) {
        first = temp;
        /*  If the data of the new node is bigger than the 
            data of the currently first node */
    } else if (data > first->data) {
        temp->next = first;
        first = temp;
    } else {
        /*  Calls the helper function to handle sorting when 
            when the new node isn't supposed to be in neither
            the first position (index 0) or the second position
            (index 1).
         */
        insert_sort(first, temp);
    }

    /* ===================== */

    // if (is_empty()) {
    //      first = new_node;
    //      new_node->next = NULL;
    // } else if (size() == 1) {
    //     if (first->data > value) {
    //     tmp->next = first;
    //     first = tmp;
    //     } else {
    //         first->next = new_node;
    //     }
    // } else {
    //     if (first->data > value) {
    //         tmp->next = first;
    //         first = tmp;
    //     } else {
    //         tmp = first->next;
    //         while (tmp->next->data > value) {
    //             tmp = tmp->next;
    //         } 
    //         tmp = new_node;

    //     }
    // } 

    // if (is_empty()) {
    //     first = tmp;
    //     tmp->next = NULL;
    // } else if (first->data > value) {
    //     tmp->next = first;
    //     first = tmp;
    // }

    //tmp->next = first;
    //first = tmp;
    
}



/* ======== Test ====================================== */

/* Only works if you insert <= three values. It's shit. */
void Sorted_List::insert_sort(Node* current_node, Node* new_node) {
    if (current_node->next == nullptr) {
        current_node->next = new_node;
        new_node->next = nullptr;
        return;
    } 
    Node* next_node{current_node->next};
    if (new_node->data <= next_node->data) {
        current_node->next = new_node;
        new_node->next = next_node;
        return;
    } else {
        /* Recursivly calls itself to continue sorting */
        insert_sort(next_node, new_node);
    }
}

/* ===================================================== */



void Sorted_List::remove(int const &index) {
    Node* tmp = first;
    Node* last = first;
    for (int i{0}; i < size(); ++i) {
        if (i == index) {
            last->next = tmp->next;
            delete tmp;
        } else {
        last = tmp;
        tmp = tmp->next;
        }
        //tmp = first->next;
    }
}

void Sorted_List::print() const {
    if (!is_empty()) {
        Node* tmp = first;
        for (int i{0}; i < size(); ++i) {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << endl;
    } else {
        cout << "The list is empty." << endl;
    }
}

int Sorted_List::getValueAt(int const &index) const {
    if (!is_empty()) {
        Node* tmp = first;
        for (int i{size()}; i > (index + 1); --i) {
            tmp = tmp->next;
        }
        return tmp->data;
    }
}

int Sorted_List::size() const {
    Node* tmp = first;
    int size{0};
    while (tmp != NULL) {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

bool Sorted_List::is_empty() const {
    return first == NULL;
}
