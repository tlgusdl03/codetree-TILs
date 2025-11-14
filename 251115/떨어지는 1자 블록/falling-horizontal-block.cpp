#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

void solve() {
    int row = 0;

    while (true) {
        bool stop = false;

        for (int i = k - 1; i < k + m - 1; i++) {
            if (row + 1 >= n - 1 || grid[row + 1][i] == 1) {
                stop = true;
                break;
            }
        }

        if (stop) break;

        row++;
    }

    for (int i = k - 1; i < k + m - 1; i++) {
        grid[row][i] = 1;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    solve();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
