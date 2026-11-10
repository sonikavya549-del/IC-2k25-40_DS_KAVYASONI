#include <iostream>
#include <stack>
using namespace std;

int main() {
    int a[10][10] = {0};
    int visited[10] = {0};
    int n, e, u, v;

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter edges: ";
    cin >> e;

    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    stack<int> s;

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    s.push(start);

    while(!s.empty()) {
        int x = s.top();
        s.pop();

        if(visited[x] == 0) {
            cout << x << " ";
            visited[x] = 1;
        }

        for(int i = n - 1; i >= 0; i--) {
            if(a[x][i] == 1 && visited[i] == 0) {
                s.push(i);
            }
        }
    }

    return 0;
}
