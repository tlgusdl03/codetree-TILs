#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int grid[100][100];
int r, c;
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void bfs(int row, int col, int cur_Num) {
    queue<pair<int, int>> q;

    visited[row][col] = true;
    q.push({row, col});

    while(!q.empty()) {
        int cur_Row = q.front().first;
        int cur_Col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_Row = cur_Row + dx[i];
            int next_Col = cur_Col + dy[i];

            if (!isInRange(next_Row, next_Col)) continue;

            int next_Num = grid[next_Row][next_Col];

            if (!visited[next_Row][next_Col] && next_Num < cur_Num) {
                visited[next_Row][next_Col] = true;
                q.push({next_Row, next_Col});
            }
        }
    }

}

void solve(int row, int col) {
    int cur_Row = row;
    int cur_Col = col;
    int cur_Num = grid[cur_Row][cur_Col];

    int next_Row = cur_Row;
    int next_Col = cur_Col;
    int next_Num = 0;

    for (int i = 0; i < k; i++) {
        memset(visited, false, sizeof(visited));

        bfs(cur_Row, cur_Col, cur_Num);

        next_Row = cur_Row;
        next_Col = cur_Col;
        next_Num = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (visited[r][c]) {
                    if (next_Num < grid[r][c] && grid[r][c] < cur_Num) {
                        next_Row = r;
                        next_Col = c;
                        next_Num = grid[r][c];
                    }
                }
            }
        }

        if (next_Row == cur_Row && next_Col == cur_Col) {
            break;
        }
        else {
            cur_Row = next_Row;
            cur_Col = next_Col;
            cur_Num = next_Num;
        }
    }

    cout << cur_Row + 1 << " " << cur_Col + 1 << '\n';
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    solve(r - 1, c - 1);

    return 0;
}
