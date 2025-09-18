#include <iostream>

using namespace std;

int n, m;
int arr[100];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int result = 0;

    for (int i = 1; i <= n; i++) {
        int idx = i;
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            idx = arr[idx];
            sum += arr[idx];
        }
        result = max(result, sum);
    }

    cout << result;

    return 0;
}