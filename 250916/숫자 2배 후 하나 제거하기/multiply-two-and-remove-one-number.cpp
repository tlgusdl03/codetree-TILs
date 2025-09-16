#include <iostream>

using namespace std;

int n;
int arr[100];
int doubleArr[100];
int deletedArr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 100 * 100 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idx = 0;
            for (int k = 0; k < n; k++) {
                if (i == k) {
                    doubleArr[k] = arr[k] * 2;
                }
                else {
                    doubleArr[k] = arr[k];
                }
            }

            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                deletedArr[idx++] = doubleArr[k];
            }

            int temp = 0;

            for (int k = 0; k < n - 2; k++) {
                temp += abs(deletedArr[k] - deletedArr[k + 1]);
            }

            result = min(result, temp);
        }
    }

    cout << result;

    return 0;
}