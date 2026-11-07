
#include <iostream>
using namespace std;

struct Node {
    string name;
    int value;
    Node *left, *right;
};

Node* insert(Node* root, string name, int value) {
    if (root == NULL) {
        Node* n = new Node;
        n->name = name;
        n->value = value;
        n->left = NULL;
        n->right = NULL;
        return n;
    }

    if (name < root->name)
        root->left = insert(root->left, name, value);
    else
        root->right = insert(root->right, name, value);

    return root;
}

void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        cout << root->name << " = " << root->value << endl;
        display(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, "age", 19);
    root = insert(root, "marks", 90);
    root = insert(root, "roll", 10);

    cout << "Symbol Table:\n";
    display(root);

    return 0;
}
