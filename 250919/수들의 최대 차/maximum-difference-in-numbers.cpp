#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[1000];
int MIN = 10001;
int MAX = 0;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        MIN = min(MIN, arr[i]);
        MAX = max(MAX, arr[i]);
    }

    int result = 0;
    for (int i = MIN; i <= MAX; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (i <= arr[j] && arr[j] <= i + K) temp++;
        }
        result = max(result, temp);
    }

    cout << result;
    return 0;
}