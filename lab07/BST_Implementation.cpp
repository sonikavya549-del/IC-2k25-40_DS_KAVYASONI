#include <iostream>
#include <queue>
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

    queue<int> q;

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        for(int i = 0; i < n; i++) {
            if(a[x][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
