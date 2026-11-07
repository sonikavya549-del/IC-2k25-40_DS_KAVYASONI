
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL) {
        Node* n = new Node;
        n->data = x;
        n->left = NULL;
        n->right = NULL;
        return n;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 80);

    Node* temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    cout << "Minimum: " << temp->data << endl;

    temp = root;

    while (temp->right != NULL)
        temp = temp->right;

    cout << "Maximum: " << temp->data;

    return 0;
}
