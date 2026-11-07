
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

int search(Node* root, int x) {
    if (root == NULL)
        return 0;

    if (root->data == x)
        return 1;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    if (search(root, x))
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}
