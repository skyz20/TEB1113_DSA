/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab : Lab 4 (Circular Doubly Linked List)
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next_pointer;
    Node* prev_pointer;

    Node(string name) {
        this->name = name;
        this->next_pointer = nullptr;
        this->prev_pointer = nullptr;
    }
};

class Linkedlist {
public:
    Node* head;
    Node* tail;

    Linkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    void insert_node(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            head->next_pointer = head;
            head->prev_pointer = head;
        } else {
            new_node->prev_pointer = tail;
            new_node->next_pointer = head;
            tail->next_pointer = new_node;
            head->prev_pointer = new_node;
            tail = new_node;
        }
    }

    void delete_node(string name) {
        if (head == nullptr) return; // Empty list

        Node* curr = head;

        // Only one node
        if (head == tail && head->name == name) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        // Search for the node to delete
        do {
            if (curr->name == name) {
                if (curr == head) {
                    head = head->next_pointer;
                }
                if (curr == tail) {
                    tail = tail->prev_pointer;
                }

                curr->prev_pointer->next_pointer = curr->next_pointer;
                curr->next_pointer->prev_pointer = curr->prev_pointer;
                delete curr;
                return;
            }
            curr = curr->next_pointer;
        } while (curr != head);
    }

    void display_list() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* currNode = head;
        do {
            cout << currNode->name << " <-> ";
            currNode = currNode->next_pointer;
        } while (currNode != head);
        cout << head->name << endl;
    }
};

int main() {
    cout << "Circular Doubly Linked List" << endl;
    Linkedlist list;

    list.insert_node("Ali");
    list.insert_node("Ahmed");
    list.insert_node("Alice");

    cout << "\nList before deletion:\n";
    list.display_list();

    list.delete_node("Ahmed");

    cout << "\nList after deleting Ahmed:\n";
    list.display_list();

    list.delete_node("Ali");

    cout << "\nList after deleting Ali:\n";
    list.display_list();

    return 0;
}