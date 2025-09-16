#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[20], y[20];
int cntX[10], cntY[10];

int permutation[8][3] = {
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1}
};

bool getResult(int a, int b, int c) {
    int arrX[3] = {x[a], x[b], x[c]};
    int arrY[3] = {y[a], y[b], y[c]};

    for (int perm = 0; perm < 8; perm++) {
        bool allCovered = true;
        for (int i = 0; i < n; i++) {
            bool covered = false;
            for (int j = 0; j < 3; j++) {
                if (permutation[perm][j] == 1) {
                    if (x[i] == arrX[j]) {
                        covered = true;
                        break;
                    }
                }
                else {
                    if (y[i] == arrY[j]) {
                        covered = true;
                        break;
                    }
                }
            }
            if (!covered) {
                allCovered = false;
                break;
            }
        }
        if (allCovered) return true;
    }

    return false;
}

int main() {
    cin >> n;

    if (n < 4) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        cntX[x[i]]++;
        cntY[y[i]]++;
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