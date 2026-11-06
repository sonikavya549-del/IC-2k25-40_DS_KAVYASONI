#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;

    q.push("Aman");
    q.push("Riya");
    q.push("Kavya");

    cout << q.front() << " is being served\n";
    q.pop();

    cout << q.front() << " is being served\n";
    q.pop();

    cout << q.front() << " is being served\n";
    q.pop();

    return 0;
}
