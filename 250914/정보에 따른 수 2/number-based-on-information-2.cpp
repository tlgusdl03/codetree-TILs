#include <iostream>

using namespace std;

int T, a, b;
int x[100];
char c[100];

int main() {
    cin >> T >> a >> b;

    for (int i = 0; i < T; i++) {
        cin >> c[i] >> x[i];
    }

    int result = 0;

    for (int i = a; i <= b; i++) {
        int minSDistance = 1001;
        int minNDistance = 1001;

        for (int j = 0; j < T; j++) {
            if (c[j] == 'S') {
                minSDistance = min(minSDistance, abs(i - x[j]));
            }
            else if (c[j] == 'N') {
                minNDistance = min(minNDistance, abs(i - x[j]));
            }
        }

        if (minSDistance == 1001 && minNDistance == 1001) continue;
        if (minSDistance <= minNDistance) result++;
    }

    cout << result;
    return 0;
}