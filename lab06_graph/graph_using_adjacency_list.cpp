#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, e;

    cout << "Enter vertices: ";
    cin >> n;

    vector<int> a[10];

    cout << "Enter edges: ";
    cin >> e;

    int u, v;

    for(int i = 0; i < e; i++) {
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cout << i << " -> ";

        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
