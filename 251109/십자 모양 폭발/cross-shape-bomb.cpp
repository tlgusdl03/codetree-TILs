#include <iostream>
#include <deque>
using namespace std;

int n;
int grid[200][200];
int r, c;

bool isInRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    r--;
    c--;

    int len = grid[r][c];

    int currentRow = r;
    int currentCol = c;
    for (int i = 0; i < len; i++) {
        if (isInRange(currentRow, currentCol)) {
            grid[currentRow][currentCol] = 0;
            currentCol--;
        }
        else {
            break;
        }
    }

    currentRow = r;
    currentCol = c;
    for (int i = 0; i < len; i++) {
        if (isInRange(currentRow, currentCol)) {
            grid[currentRow][currentCol] = 0;
            currentRow--;
        }
        else {
            break;
        }
    }

    currentRow = r;
    currentCol = c;
    for (int i = 0; i < len; i++) {
        if (isInRange(currentRow, currentCol)) {
            grid[currentRow][currentCol] = 0;
            currentCol++;
        }
        else {
            break;
        }
    }

    currentRow = r;
    currentCol = c;
    for (int i = 0; i < len; i++) {
        if (isInRange(currentRow, currentCol)) {
            grid[currentRow][currentCol] = 0;
            currentRow++;
        }
        else {
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        deque<int> temp;
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][j] != 0) temp.push_back(grid[i][j]);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (temp.empty()) {
                grid[i][j] = 0;
            }
            else {
                grid[i][j] = temp.front();
                temp.pop_front();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
