#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[200000];

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }

    sort (arr, arr + 2 * n);

    int result = 1000000001;

    for (int i = 0; i < n; i++) {
        result = min(result, abs(arr[i + n] - arr[i]));
    }

    cout << result;

    return 0;
}

