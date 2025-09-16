#include <iostream>

using namespace std;

int n;
int x[20], y[20];

bool getResult (int a, int b, int c) {
    int x1 = x[a];
    int y1 = y[a];
    int x2 = x[b];
    int y2 = y[b];
    int x3 = x[c];
    int y3 = y[c];

    for (int i = 0; i < n; i++) {
        if (x[i] != x1 && x[i] != x2 && x[i] != x3 && y[i] != y1 && y[i] != y2 && y[i] != y3) return false;
    }

    return true;
}

int main() {
    cin >> n;

    if (n <= 3) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (getResult(i, j, k)) {
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;
}