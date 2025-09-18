#include <iostream>
#include <string>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (seat[i] == '1') continue;
        int lastPos = -1;
        int distance = N;
        for (int j = 0; j < N; j++) {
            if (seat[j] == '1' || i == j) {
                if (lastPos == -1) {
                    lastPos = j;
                }
                else {
                    distance = min(distance, j - lastPos);
                    lastPos = j;
                }
            }
        }

        result = max(result, distance);
    }

    cout << result;

    return 0;
}