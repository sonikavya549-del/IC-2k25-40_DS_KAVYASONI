#include <iostream>
using namespace std;

int main() {
    int a[10][10], s[100][3];
    int r, c, k = 1;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    s[0][0] = r;
    s[0][1] = c;
    int count = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
                count++;
            }
        }
    }

    s[0][2] = count;

    cout << "\nSparse Matrix (Triple Format):\n";
    for (int i = 0; i <= count; i++)
        cout << s[i][0] << " "
             << s[i][1] << " "
             << s[i][2] << endl;

    return 0;
}
