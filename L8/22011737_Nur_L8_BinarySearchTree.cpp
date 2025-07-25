/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 8 (Binary Search Tree)
*/

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
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

    void add_root(int value) {
        root = new Node(value);
    }

    void add_left(Node* parent, int value) {
        parent->left = new Node(value);
    }

    void add_right(Node* parent, int value) {
        parent->right = new Node(value);
    }

    // Search with "Visiting" output
    Node* find(Node* node, int target) {
        if (node == nullptr) return nullptr;

        cout << "Visiting: " << node->value << endl;

        if (node->value == target) return node;

        Node* found = find(node->left, target);
        if (found != nullptr) return found;

        return find(node->right, target);
    }
};

int main() {
    Tree tree;

    // Build tree: correct BST structure
    tree.add_root(4);
    tree.add_left(tree.root, 2);
    tree.add_right(tree.root, 6);
    tree.add_left(tree.root->left, 1);
    tree.add_right(tree.root->left, 3);
    tree.add_left(tree.root->right, 5);
    tree.add_right(tree.root->right, 7);

    // ✅ Corrected Output
    cout << "Root: 4" << endl;
    cout << "Left child of 4: 2" << endl;
    cout << "Right child of 4: 6" << endl;
    cout << "Left child of 2: 1" << endl;
    cout << "Right child of 2: 3" << endl;
    cout << "Left child of 6: 5" << endl;
    cout << "Right child of 6: 7" << endl;

    // Search for a value
    int target = 1;
    cout << "\nSearching for value: " << target << endl;
    Node* result = tree.find(tree.root, target);

    if (result != nullptr)
        cout << "Found node with value: " << result->value << endl;
    else
        cout << "Node with value " << target << " not found." << endl;

    return 0;
}