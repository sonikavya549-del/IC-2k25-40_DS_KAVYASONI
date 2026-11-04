#include <iostream>
using namespace std;

int *q, front = -1, rear = -1, size;

void enqueue(int x) {
    if (rear == size - 1)
        cout << "Queue Overflow\n";
    else {
        if (front == -1) front = 0;
        q[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        cout << "Queue Underflow\n";
    else
        cout << "Deleted: " << q[front++] << endl;
}

void display() {
    if (front == -1 || front > rear)
        cout << "Queue is empty\n";
    else {
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
}

int main() {
    cout << "Enter queue size: ";
    cin >> size;

    q = new int[size];

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    dequeue();
    display();

    delete[] q;
    return 0;
}
