#include <iostream>

using namespace std;

int n;
int grid[50][50];
int backup[50][50];

void bomdAndFall(int row, int col) {
    int len = grid[row][col];

    int curX = row;
    int curY = col;
    for (int i = 0; i < len; i++) {
        grid[curX][curY] = 0;
        curY--;
        if (curY < 0) break;
    }

    curX = row;
    curY = col;
    for (int i = 0; i < len; i++) {
        grid[curX][curY] = 0;
        curX--;
        if (curX < 0) break;
    }

    curX = row;
    curY = col;
    for (int i = 0; i < len; i++) {
        grid[curX][curY] = 0;
        curY++;
        if (curY >= n) break;
    }

    curX = row;
    curY = col;
    for (int i = 0; i < len; i++) {
        grid[curX][curY] = 0;
        curX++;
        if (curX >= n) break;
    }

    for (int j = 0; j < n; j++) {
        int temp[50] = {0, };
        int idx = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][j] != 0) {
                temp[idx] = grid[i][j];
                idx--;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            grid[i][j] = temp[i];
        }
    }
}

int countPair() {
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = grid[i][j];

            if (cur == 0) continue;

            if (i + 1 < n && cur == grid[i + 1][j]) {
                if (i - 1 < 0 && i + 2 >= n) {
                    result++;
                }
                else if (i - 1 < 0 || cur != grid[i - 1][j]) {
                    result++;
                }
                else if (i + 2 >= n || cur != grid[i + 2][j]) {
                    result++;
                }
                else if (cur != grid[i - 1][j] && cur != grid[i + 1][j]) {
                    result++;
                }
            }

            if (j + 1 < n && cur == grid[i][j + 1]) {
                if (j - 1 < 0 && j + 2 >= n ) {
                    result++;
                }
                else if (j - 1 < 0 || cur != grid[i][j - 1]) {
                    result++;
                }
                else if (j + 2 >= n || cur != grid[i][j + 2]) {
                    result++;
                }
                else if (cur != grid[i][j - 1] && cur != grid[i][j + 2]) {
                    result++;
                }
            }
        }
    }

    return result;
}

void restore() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = backup[i][j];
        }
    }
}

void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    cout << countPair() << '\n';
    cout << '\n';
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            backup[i][j] = grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bomdAndFall(i, j);
            result = max(result, countPair());
            // debug();
            restore();
        }
    }

    cout << result;
    return 0;
}
