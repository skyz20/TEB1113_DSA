/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab : Lab 3 (Singly Linked List)
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

    void insert_node(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next_pointer = node;
            tail = node;
        }
    }

    void delete_node(Node* node) {
        if (head == nullptr || node == nullptr)
            return;

        if (head == node) {
            Node* temp = head;
            head = head->next_pointer;
            delete temp;
            return;
        }

        Node* prev = head;
        while (prev->next_pointer != nullptr && prev->next_pointer != node) {
            prev = prev->next_pointer;
        }

        if (prev->next_pointer == node) {
            prev->next_pointer = node->next_pointer;
            if (node == tail) {
                tail = prev;
            }
            delete node;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " -> ";
            currNode = currNode->next_pointer;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Alice");
    Node* node3 = new Node("Ahmed");

    Linkedlist std_names;

    std_names.insert_node(node1);
    std_names.insert_node(node2);
    std_names.insert_node(node3);
    
    cout << "Before deleting Alice: \n";
    std_names.display_list();
    std_names.delete_node(node2);
    cout << "\nAfter deleting Alice: \n";
    std_names.display_list();

    // Clean up remaining nodes
    std_names.delete_node(node1);
    std_names.delete_node(node3);

    return 0;
}
