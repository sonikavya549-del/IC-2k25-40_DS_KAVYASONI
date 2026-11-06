#include <iostream>
using namespace std;

#define MAX 5

class Deque {
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) ||
               (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = MAX - 1;
        else
            front--;

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertFront(5);

    d.display();

    d.deleteFront();
    d.display();

    d.deleteRear();
    d.display();

    return 0;
}
