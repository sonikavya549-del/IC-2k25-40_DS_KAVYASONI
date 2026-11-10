#include <iostream>
using namespace std;

int main() {
    int n, e;
    int a[10][10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int u, v;

    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    cout << "Adjacency Matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
