/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab : Lab 5 (Stack - Array)
*/

#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100;  // maximum stack size
    string arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string name) {
        if (top >= MAX - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = name;
    }

    void isEmpty() {
        cout << "Stack is empty!" << endl;
    }

    void pop() {
        if (top == -1) {
            isEmpty();
        } else {
            cout << arr[top--] << endl;
        }
    }

    void peek() {
        if (top == -1) {
            isEmpty();
        } else {
            cout << arr[top] << endl;
        }
    }

    void display_stack() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "Stack: ";
    Stack stack;

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alice");
    stack.display_stack();

    cout << "\nStack (Peek): \n";
    stack.peek();
    stack.peek();
    stack.peek();
    stack.peek();
    
    cout << "\nStack (Pop): \n";
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    
    cout << "\nStack after popping: \n";
    stack.display_stack();
    return 0;
}