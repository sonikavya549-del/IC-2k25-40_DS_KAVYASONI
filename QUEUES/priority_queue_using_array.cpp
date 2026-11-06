#include <iostream>
using namespace std;

#define MAX 5

class PriorityQueue {
    int arr[MAX];
    int priority[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void enqueue(int x, int p) {
        if (size == MAX) {
            cout << "Queue is full\n";
            return;
        }

        arr[size] = x;
        priority[size] = p;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }

        int pos = 0;

        for (int i = 1; i < size; i++) {
            if (priority[i] < priority[pos])
                pos = i;
        }

        cout << "Deleted: " << arr[pos] << endl;

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
            priority[i] = priority[i + 1];
        }

        size--;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " Priority: "
                 << priority[i] << endl;
        }
    }
};

int main() {
    PriorityQueue q;

    q.enqueue(10, 3);
    q.enqueue(20, 1);
    q.enqueue(30, 2);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}
