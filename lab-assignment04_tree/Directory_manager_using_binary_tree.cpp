
#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *left, *right;
};

Node* create(string name) {
    Node* n = new Node;
    n->name = name;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void display(Node* root) {
    if (root != NULL) {
        cout << root->name << endl;
        display(root->left);
        display(root->right);
    }
}

int main() {
    Node* root = create("College");

    root->left = create("BCA");
    root->right = create("MCA");

    root->left->left = create("Semester 1");
    root->left->right = create("Semester 2");

    cout << "Directory Structure:" << endl;
    display(root);

    return 0;
}
