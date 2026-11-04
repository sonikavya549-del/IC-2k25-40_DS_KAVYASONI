#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1)
            cout << "Stack Overflow\n";
        else {
            top++;
            arr[top] = x;
            cout << x << " pushed\n";
        }
    }

    void pop() {
        if (top == -1)
            cout << "Stack Underflow\n";
        else {
            cout << arr[top] << " popped\n";
            top--;
        }
    }

    void display() {
        if (top == -1)
            cout << "Stack is empty\n";
        else {
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack: ";
    s.display();

    s.pop();

    cout << "After pop: ";
    s.display();

    return 0;
}
