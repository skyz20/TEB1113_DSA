/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 6 (Queue - Circular)
*/

#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    static const int MAX = 5;  // fixed size for demonstration
    string arr[MAX];
    int front;
    int rear;
    int count; // tracks number of elements

public:
    CircularQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isFull() {
        return count == MAX;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        arr[rear] = name;
        rear = (rear + 1) % MAX;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Removing: " << arr[front] << endl;
        front = (front + 1) % MAX;
        count--;
    }

    void display_queue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX;
            cout << arr[index] << " <- ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");
    queue.enqueue("Amin");

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