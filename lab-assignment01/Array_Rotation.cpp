#include <iostream>
using namespace std;

int main() {
    int arr[10], temp;

    cout << "Enter 10 elements: ";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    temp = arr[0];

    for (int i = 0; i < 9; i++)
        arr[i] = arr[i + 1];

    arr[9] = temp;

    cout << "Array after rotation: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}
