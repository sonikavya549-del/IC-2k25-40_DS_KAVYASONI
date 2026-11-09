
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    Node *head = NULL, *temp, *newnode;
    int n, pos;

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

    cout << "Enter position: ";
    cin >> pos;

    newnode = new Node;

    cout << "Enter value: ";
    cin >> newnode->data;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Position";
            return 0;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
