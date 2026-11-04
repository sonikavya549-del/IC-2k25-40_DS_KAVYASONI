
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
        else
            arr[++top] = x;
    }

    int pop() {
        if (top == -1)
            return -1;

        return arr[top--];
    }

    int peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;

    return 0;
}

int main() {
    Stack values;
    Stack operators;

    char expression[MAX];

    cout << "Enter expression: ";
    cin >> expression;

    int i = 0;

    while (expression[i] != '\0') {

        char ch = expression[i];

        if (ch >= '0' && ch <= '9') {
            values.push(ch - '0');
        }

        else if (ch == '(') {
            operators.push(ch);
        }

        else if (ch == ')') {
            while (operators.peek() != '(') {
                int b = values.pop();
                int a = values.pop();
                char op = operators.pop();

                values.push(calculate(a, b, op));
            }

            operators.pop();
        }

        else {
            while (!operators.isEmpty() &&
                   precedence(operators.peek()) >= precedence(ch)) {

                int b = values.pop();
                int a = values.pop();
                char op = operators.pop();

                values.push(calculate(a, b, op));
            }

            operators.push(ch);
        }

        i++;
    }

    while (!operators.isEmpty()) {
        int b = values.pop();
        int a = values.pop();
        char op = operators.pop();

        values.push(calculate(a, b, op));
    }

    cout << "Result: " << values.pop();

    return 0;
}
