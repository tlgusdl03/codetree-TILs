#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define STONE_NUM 8
using namespace std;

int n, k, m;
int grid[100][100];
int copy_Grid[100][100];
int r[10000], c[10000];
bool flag[8];
bool visited[100][100];
int answer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> stones;

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void make_Copy_Grid() {
    memcpy(copy_Grid, grid, sizeof(grid));  
    
    for (int i = 0; i < STONE_NUM; i++) { 
        if (flag[i]) {
            copy_Grid[stones[i].first][stones[i].second] = 0;
        }
    }
}

void BFS(int row, int col) {
    queue<pair<int, int>> q;

    visited[row][col] = true;
    q.push({row, col});

    while (!q.empty()) {
        int cur_Row = q.front().first;
        int cur_Col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_Row = cur_Row + dx[i];
            int next_Col = cur_Col + dy[i];

            if (isInRange(next_Row, next_Col) && copy_Grid[next_Row][next_Col] == 0 && !visited[next_Row][next_Col]) {
                visited[next_Row][next_Col] = true;
                q.push({next_Row, next_Col});
            }
        }
    }   
}

void solve() {
    memset(visited, false, sizeof(visited));
    make_Copy_Grid();

    for (int i = 0; i < k; i++) {
        int row = r[i];
        int col = c[i];

        if (!visited[row][col] && copy_Grid[row][col] == 0) BFS(row, col);
    }

    int temp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) temp++;
        }
    }

    answer = max(answer, temp);
}

void make_choice(int idx, int cnt) {
    if (cnt == m) {
        solve();
        return;
    }
    if (idx >= stones.size()) return;

    flag[idx] = true;
    make_choice(idx + 1, cnt + 1);

    flag[idx] = false;
    make_choice(idx + 1, cnt);
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                stones.push_back({i, j});
            } 
        }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    make_choice(0, 0);

    cout << answer << '\n';

    return 0;
}
