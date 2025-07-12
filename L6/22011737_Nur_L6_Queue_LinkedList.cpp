/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 6 (Queue - Linked List)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* newNode = new Node(name);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Removing: " << temp->name << endl;
        front = front->next;
        if (!front) rear = nullptr; // if queue becomes empty
        delete temp;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display_queue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << " <- ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");

    cout << "Queue: ";
    queue.display_queue();
    
    cout << "\n";
    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}