#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_DISTANCE 10001
using namespace std;

int n, h, m;
int grid[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int answer[100][100];
bool visited[100][100];
vector<pair<int, int>> shelter;

struct Node {
    int row, col, step;
};

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void BFS() {
    queue<Node> q;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < shelter.size(); i++) {
        int r = shelter[i].first;
        int c = shelter[i].second;
        visited[r][c] = true;
        q.push({r, c, 0});
    }
    
    while(!q.empty()) {
        int cur_R = q.front().row;
        int cur_C = q.front().col;
        int cur_S = q.front().step;
        q.pop();

        if (grid[cur_R][cur_C] == 2) {
            answer[cur_R][cur_C] = min(answer[cur_R][cur_C], cur_S);
        }

        for (int i = 0; i < 4; i++) {
            int next_R = cur_R + dx[i];
            int next_C = cur_C + dy[i];
            int next_S = cur_S + 1;

            if (isInRange(next_R, next_C) 
            && grid[next_R][next_C] != 1 
            && !visited[next_R][next_C]) {
                visited[next_R][next_C] = true;
                q.push({next_R, next_C, next_S});
            }
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer[i][j] = MAX_DISTANCE;
        }
    }

    BFS();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 2) answer[i][j] = 0;
            if (answer[i][j] == MAX_DISTANCE) answer[i][j] = -1;
        }
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
            if (grid[i][j] == 3) {
                shelter.push_back({i, j});
            }
        }
    }

    solve();

    return 0;
}
