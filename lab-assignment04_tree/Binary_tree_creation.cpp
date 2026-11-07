
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

int main() {
    Node *root = new Node;

    root->data = 10;

    root->left = new Node;
    root->left->data = 20;

    root->right = new Node;
    root->right->data = 30;

    root->left->left = NULL;
    root->left->right = NULL;

    root->right->left = NULL;
    root->right->right = NULL;

    cout << "Root Node: " << root->data << endl;
    cout << "Left Node: " << root->left->data << endl;
    cout << "Right Node: " << root->right->data;

    return 0;
}
