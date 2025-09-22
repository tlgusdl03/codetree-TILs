#include <iostream>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 10000 * 100 + 1;

    for (int i = 1; i <= 10000; i++) {
        // i : 가능한 최소값
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] < i) {
                temp += abs(i - arr[j]);
            }
            else if (arr[j] - i > k) {
                temp += abs(arr[j] - (k + i));
            }
        }
        result = min(result, temp);
    }

    cout << result;
    
    return 0;
}