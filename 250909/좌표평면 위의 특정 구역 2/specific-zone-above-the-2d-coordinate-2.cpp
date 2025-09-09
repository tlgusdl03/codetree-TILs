#include <iostream>

using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int result = 40000 * 40000 + 1;
    for (int i = 0; i < N; i++) {
        int maxX = 0, minX = 40001, maxY = 0, minY = 40001;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            maxX = max(maxX, x[j]);
            minX = min(minX, x[j]);
            maxY = max(maxY, y[j]);
            minY = min(minY, y[j]);
        }

        result = min(result, (maxX - minX) * (maxY - minY));
    }

    cout << result;

    return 0;
}