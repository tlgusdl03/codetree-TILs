#include <iostream>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < n - k + 1; i++){
        int temp = 0;
        for (int j = i; j < i + k; j++){
            temp += arr[j];
        }
        result = max(result, temp);
    }

    cout << result;

    return 0;
}