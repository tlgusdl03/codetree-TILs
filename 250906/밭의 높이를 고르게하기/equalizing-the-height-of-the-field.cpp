#include <iostream>
#define MAX_R 100
using namespace std;

int N, H, T;
int arr[100];

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 100 * 200 + 1;

    for (int i = 0; i < N - T + 1; i++) {
        int sum = 0;
        for (int j = i; j < i + T; j++) {
            sum += abs(arr[j] - H);
        }
        result = min(result, sum);
    }

    cout << result;

    return 0;
}