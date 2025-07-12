/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab : Lab 4 (Circular Singly Linked List)
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next_pointer;

    Node(string name) {
        this->name = name;
        this->next_pointer = nullptr;
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
            tail->next_pointer = head;  // circular
        } else {
            tail->next_pointer = new_node;
            tail = new_node;
            tail->next_pointer = head;  // keep it circular
        }
    }

    void delete_node(string name) {
        if (head == nullptr) return; // Empty list

        Node* curr = head;
        Node* prev = tail;

        // Only one node
        if (head == tail && head->name == name) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        // Deleting head
        if (head->name == name) {
            head = head->next_pointer;
            tail->next_pointer = head;
            delete curr;
            return;
        }

        // Deleting middle or tail
        curr = head;
        do {
            prev = curr;
            curr = curr->next_pointer;
            if (curr->name == name) {
                prev->next_pointer = curr->next_pointer;
                if (curr == tail)
                    tail = prev;
                delete curr;
                return;
            }
        } while (curr != head);
    }

    void display_list() {
       Node* currNode = head;
        do {
            cout << currNode->name << " -> ";
            currNode = currNode->next_pointer;
        } while (currNode != head);
        cout << head->name << endl;
    }
};

int main() {
    cout << "Circular Singly Linked List" << endl;
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