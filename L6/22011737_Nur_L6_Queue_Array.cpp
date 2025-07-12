/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 6 (Queue - Array)
*/

#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int MAX = 100;  // Max queue size
    string arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear >= MAX - 1;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[++rear] = name;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Removing: " << arr[front++] << endl;
    }

    void display_queue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " <- ";
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

    queue.display_queue();
    
    cout << "\n";
    queue.dequeue();
    queue.dequeue();

    cout << "After Dequeue: \n";
    queue.display_queue();

    queue.enqueue("Sarah");
    queue.enqueue("Dina");

    cout << "\nAfter Enqueue again: \n";
    queue.display_queue();

    return 0;
}