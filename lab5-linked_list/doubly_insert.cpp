
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

int main() {
    Node *head = NULL, *temp, *newnode;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        newnode = new Node;
        cin >> newnode->data;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    newnode = new Node;

    cout << "Enter value: ";
    cin >> newnode->data;

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
