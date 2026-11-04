
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top == MAX - 1)
            cout << "Stack Overflow\n";
        else {
            top++;
            arr[top] = x;
        }
    }

    char pop() {
        if (top == -1)
            return '\0';
        else {
            char x = arr[top];
            top--;
            return x;
        }
    }

    char peek() {
        if (top == -1)
            return '\0';
        else
            return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main() {
    Stack s;

    char infix[MAX], postfix[MAX];
    int j = 0;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (int i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {

            postfix[j] = ch;
            j++;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j] = s.pop();
                j++;
            }

            if (!s.isEmpty())
                s.pop();
        }

        else {
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(ch) ||
                   (precedence(s.peek()) == precedence(ch) && ch != '^'))) {

                postfix[j] = s.pop();
                j++;
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix[j] = s.pop();
        j++;
    }

    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix;

    return 0;
}
