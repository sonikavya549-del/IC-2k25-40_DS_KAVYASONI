
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

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int x) {
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else {
        if (root->left == NULL)
            return root->right;

        if (root->right == NULL)
            return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout << "Before deletion: ";
    inorder(root);

    root = deleteNode(root, 30);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}
