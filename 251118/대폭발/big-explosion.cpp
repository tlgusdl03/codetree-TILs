#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c;
bool result[101][101] = {false, };

bool isInRange(int r, int c) {
    return (0 < r && r <= n && 0 < c && c <= n);
}

void solve() {
    result[r][c] = true;
    int distance = 1;

    for (int i = 0; i < m; i++) {
        queue<int> rows;
        queue<int> cols;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (result[j][k] == true) {
                    if (isInRange(j - distance, k) && !result[j - distance][k]) {
                        rows.push(j - distance);
                        cols.push(k);
                    }
                    if (isInRange(j + distance, k) && !result[j + distance][k]) {
                        rows.push(j + distance);
                        cols.push(k);
                    }
                    if (isInRange(j, k - distance) && !result[j][k - distance]) {
                        rows.push(j);
                        cols.push(k - distance);
                    }
                    if (isInRange(j, k + distance) && !result[j][k + distance]) {
                        rows.push(j);
                        cols.push(k + distance);
                    }
                }
            }
        }

        while (!rows.empty()) {
            int r = rows.front();
            int c = cols.front();

            result[r][c] = true;

            rows.pop();
            cols.pop();
        }

        distance *= 2;
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (result[i][j]) count++;
        }
    }

    cout << count;
}

int main() {
    cin >> n >> m >> r >> c;

    solve();

    return 0;
}
