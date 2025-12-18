#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, h, m;
int grid[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[100][100];
int answer[100][100];
vector<pair<int, int>> people;

struct Node {
    int row, col, step;
};

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

int BFS(int row, int col) {
    queue<Node> q;
    visited[row][col] = true;
    q.push({row, col, 0});

    while(!q.empty()) {
        int cur_R = q.front().row;
        int cur_C = q.front().col;
        int cur_S = q.front().step;
        q.pop();

        if (grid[cur_R][cur_C] == 3) {
            return cur_S;
        }

        for (int i = 0; i < 4; i++) {
            int next_R = cur_R + dx[i];
            int next_C = cur_C + dy[i];
            int next_S = cur_S + 1;

            if (isInRange(next_R, next_C) && !visited[next_R][next_C] && grid[next_R][next_C] != 1) {
                q.push({next_R, next_C, next_S});
            }
        }
    }

    return -1;
}

void solve() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 2) {
                answer[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < people.size(); i++) {
        memset(visited, false, sizeof(visited));
        int r = people[i].first;
        int c = people[i].second;
        int result = BFS(r, c);
        answer[r][c] = result;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
} 

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                people.push_back({i, j});
            }
        }
    }

    solve();

    return 0;
}
