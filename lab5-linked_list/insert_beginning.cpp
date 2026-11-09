
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    Node *head = NULL, *temp, *newnode;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        newnode = new Node;
        cin >> newnode->data;

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    newnode = new Node;

    cout << "Enter new value: ";
    cin >> newnode->data;

    newnode->next = head;
    head = newnode;

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
