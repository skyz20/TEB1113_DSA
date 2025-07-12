/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab : Lab 5 (Stack - Linked List)
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(string name) {
        Node* new_node = new Node(name);
        
        if (top == nullptr){
            top = new_node;
        } else{
            new_node -> next_ptr = top;
            top = new_node;
        }
    }
    
    void isEmpty(){
        cout << "Stack is empty!" << endl;
        return;
    }
    
    void pop() {
        Node* current = top;
        
        if (top == nullptr){
            isEmpty();
        } else{
            cout << top->name << endl;
            top = top->next_ptr;
        }
    }
    
    void peek() {
        if (top == nullptr){
            isEmpty();
        } else{
            cout << top->name << endl;
        }
    }

    void display_stack() {
        Node* current = top;
        while (current != nullptr){
            cout << current -> name << " -> ";
            current = current -> next_ptr;
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