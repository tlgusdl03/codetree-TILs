#include <iostream>
#include <string>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    int result = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (seat[i] == '1' || seat[j] == '1') continue;

            int tempDistance = N + 1;

            int lastIdx = -1;

            for (int k = 0; k < N; k++) {
                if (lastIdx == -1) {
                    lastIdx = k;
                }
                else if (seat[k] == '1' || i == k || j == k) {
                    tempDistance = min(tempDistance, k - lastIdx);
                    lastIdx = k;
                }
            }

            result = max(result, tempDistance);
        }
    }

    cout << result;

    return 0;
}