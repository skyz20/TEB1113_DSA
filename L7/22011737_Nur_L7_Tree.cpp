/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 7 (Tree)
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    void add_left(Node* parent, string name) {
        parent->left = new Node(name);
    }

    void add_right(Node* parent, string name) {
        parent->right = new Node(name);
    }
};

int main() {
    Tree tree;

    // Construct the tree structure
    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");

    // Simplified output
    cout << "Root: A" << endl;
    cout << "Left child of A: B" << endl;
    cout << "Right child of A: C" << endl;
    cout << "Left child of B: D" << endl;
    cout << "Right child of B: E" << endl;
    cout << "Left child of C: F" << endl;
    cout << "Right child of C: G" << endl;

    return 0;
}
