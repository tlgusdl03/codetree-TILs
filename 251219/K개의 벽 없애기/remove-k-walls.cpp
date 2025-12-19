#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;
int copy_Grid[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int answer = INT_MAX;
vector<pair<int, int>> walls;
vector<pair<int, int>> selected_Walls;

struct Node {
    int row, col, step;
};

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void init() {
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copy_Grid[i][j] = grid[i][j];
        }
    }
        

    for (int i = 0; i < selected_Walls.size(); i++) {
        int r = selected_Walls[i].first;
        int c = selected_Walls[i].second;

        copy_Grid[r][c] = 0;
    }
}

void BFS() {
    queue<Node> q;

    visited[r1][c1] = true;
    q.push({r1, c1, 0});

    while(!q.empty()) {
        int cur_R = q.front().row;
        int cur_C = q.front().col;
        int cur_S = q.front().step;
        q.pop();

        if (cur_R == r2 && cur_C == c2) {
            answer = min(answer, cur_S);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_R = cur_R + dx[i];
            int next_C = cur_C + dy[i];
            int next_S = cur_S + 1;

            if (isInRange(next_R, next_C) && !visited[next_R][next_C] && copy_Grid[next_R][next_C] == 0) {
                visited[next_R][next_C] = true;
                q.push({next_R, next_C, next_S});
            }
        }
    }
}

void findAnswer() {
    init();
    BFS();
}

void solve(int idx) {
    if (selected_Walls.size() == k) {
        findAnswer();
        return;
    }

    if (idx >= walls.size()) return;

    selected_Walls.push_back(walls[idx]);
    solve(idx + 1);

    selected_Walls.pop_back();
    solve(idx + 1);
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) walls.push_back({i, j});
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    solve(0);

    if (answer == INT_MAX) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}
