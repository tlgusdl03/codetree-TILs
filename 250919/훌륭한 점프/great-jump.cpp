#include <iostream>

using namespace std;

int n, k;
int arr[100];

bool getResult(int MAX) {
    int possible_indices[100] = { };
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= MAX) {
            possible_indices[idx++] = i;
        }
    }

    for (int i = 1; i < idx; i++) {
        int dist = possible_indices[i] - possible_indices[i - 1];
        if (dist > k) return false;
    }

    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = -1;

    for (int i = max(arr[0], arr[n - 1]); i <= 100; i++) {
        if (getResult(i)) {
            result = i;
            break;
        }
    }

    cout << result;

    return 0;
}