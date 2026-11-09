
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
            newnode->next = head;
        } else {
            temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = head;
        }
    }

    if (head != NULL) {
        temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    return 0;
}
