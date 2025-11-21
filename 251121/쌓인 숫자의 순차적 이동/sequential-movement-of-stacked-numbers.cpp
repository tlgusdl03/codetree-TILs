#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> grid[20][20];
int move_nums[100];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isInRange(int r, int c) {
    return (0 <= r && r < n && 0 <= c && c < n);
}

void moveNumbers(int source_Row, int source_Col, int destination_Row, int destination_Col, int idx) {
    for (int i = idx; i < grid[source_Row][source_Col].size(); i++) {
        grid[destination_Row][destination_Col].push_back(grid[source_Row][source_Col][i]);
    }

    int remove_len = grid[source_Row][source_Col].size() - 1;

    for (int i = remove_len; i >= idx; i--) {
        grid[source_Row][source_Col].pop_back();
    }
}

void moveToNearMax(int row, int col, int idx) {
    int max_Row = row;
    int max_Col = col;
    int max_Num = 0;

    for (int i = 0; i < 8; i++) {
        int next_Row = row + dx[i];
        int next_Col = col + dy[i];

        if (!isInRange(next_Row, next_Col)) continue;
        if (grid[next_Row][next_Col].size() == 0) continue;

        for (int j = 0; j < grid[next_Row][next_Col].size(); j++) {
            if (grid[next_Row][next_Col][j] > max_Num) {
                max_Row = next_Row;
                max_Col = next_Col;
                max_Num = grid[next_Row][next_Col][j];
            }
        }
    }

    if (max_Num != 0) moveNumbers(row, col, max_Row, max_Col, idx);
}

void solve() {
    for (int i = 0; i < m; i++) {
        int target = move_nums[i];
        bool moved = false;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                for (int idx = 0; idx < grid[row][col].size(); idx++) {
                    if (target == grid[row][col][idx]) {
                        moveToNearMax(row, col, idx);
                        moved = true;
                        break;
                    }
                }
                if (moved) break;
            }
            if (moved) break;
        }
    }
}

int main() {
    cin >> n >> m;

    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            grid[i][j].push_back(num);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
    }

    solve();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j].size() == 0) {
                cout << "None\n";
                continue;
            }

            for (int k = grid[i][j].size() - 1; k >= 0; k--) {
                cout << grid[i][j][k] << " ";
            }
            cout << '\n';
        }
    }


    return 0;
}
