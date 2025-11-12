#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

void bomb(int col) {
    int row = 200;

    for (int i = 0; i < n; i++) {
        if (grid[i][col] != 0) {
            row = i;
            break;
        }
    }

    if (row == 200) return;

    int distance = grid[row][col];

    int current_Row = row;
    int current_Col = col;
    for (int i = 0; i < distance; i++) {
        grid[current_Row][current_Col] = 0;
        current_Col--;

        if (current_Col < 0) break;
    }

    current_Row = row;
    current_Col = col;
    for (int i = 0; i < distance; i++) {
        grid[current_Row][current_Col] = 0;
        current_Row--;

        if (current_Row < 0) break;
    }

    current_Row = row;
    current_Col = col;
    for (int i = 0; i < distance; i++) {
        grid[current_Row][current_Col] = 0;
        current_Col++;

        if (current_Col >= n) break;
    }

    current_Row = row;
    current_Col = col;
    for (int i = 0; i < distance; i++) {
        grid[current_Row][current_Col] = 0;
        current_Row++;

        if (current_Row >= n) break;
    }

    for (int j = 0; j < n; j++) {
        int* temp = new int[n] {0, };
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

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        bomb(c - 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
