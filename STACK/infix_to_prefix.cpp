
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

    char infix[MAX], temp[MAX], result[MAX];
    int length = 0;
    int j = 0;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    while (infix[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length; i++) {
        temp[i] = infix[length - 1 - i];
    }

    temp[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    for (int i = 0; i < length; i++) {

        char ch = temp[i];

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {

            result[j] = ch;
            j++;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result[j] = s.pop();
                j++;
            }

            if (!s.isEmpty())
                s.pop();
        }

        else {
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(ch) ||
                   (precedence(s.peek()) == precedence(ch) && ch == '^'))) {

                result[j] = s.pop();
                j++;
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        result[j] = s.pop();
        j++;
    }

    result[j] = '\0';

    for (int i = 0; i < j / 2; i++) {
        char tempChar = result[i];
        result[i] = result[j - 1 - i];
        result[j - 1 - i] = tempChar;
    }

    cout << "Prefix Expression: " << result;

    return 0;
}
