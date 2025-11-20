#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void swap(int row, int col) {
    int max_Row = row;
    int max_Col = col;
    int max_Num = 1;

    for (int i = 0; i < 8; i++) {
        int next_Row = row + dx[i];
        int next_Col = col + dy[i];

        if (!isInRange(next_Row, next_Col)) continue;

        if (grid[next_Row][next_Col] > max_Num) {
            max_Row = next_Row;
            max_Col = next_Col;
            max_Num = grid[next_Row][next_Col];
        }
    }

    grid[max_Row][max_Col] = grid[row][col];
    grid[row][col] = max_Num;
}

void solve() {
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n * n; j++) {
            bool swapped = false;
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    if (grid[row][col] == j) {
                        swap(row, col);
                        swapped = true;
                        break;
                    };
                }
                if (swapped) break;
            }
        }
    }
}

int main() {
    cin >> n >> m;

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
