#include <iostream>
using namespace std;

int a[10][10];
int visited[10] = {0};
int n;

void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(a[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int e, u, v;

    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter edges: ";
    cin >> e;

    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    DFS(start);

    return 0;
}
