#include <iostream>

using namespace std;

int n;
int arr[101] = {0, };

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        for (int j = x1; j <= x2; j++) {
            arr[j]++;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (arr[i] == n) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}