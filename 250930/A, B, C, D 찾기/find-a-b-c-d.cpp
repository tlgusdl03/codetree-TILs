#include <iostream>
#include <algorithm>
using namespace std;

int arr[15];

int main() {
    for (int i = 0; i < 15; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 15);

    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    int abcd = arr[14];

    int d = abcd - a - b - c;

    cout << a << " " << b << " " << c << " " << d;

    return 0;
}