#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k, u, d;
int grid[8][8];
vector<pair<int, int>> selected_cities;
bool visited[8][8];
int answer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool canGo(int a) {
    return (u <= a && a <= d);
}

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void BFS(int row, int col) {
    queue<pair<int, int>> q;
    visited[row][col] = true;
    q.push({row, col});

    while(!q.empty()) {
        int cur_R = q.front().first;
        int cur_C = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_R = cur_R + dx[i];
            int next_C = cur_C + dy[i];

            if (isInRange(next_R, next_C) 
            && !visited[next_R][next_C] 
            && canGo(abs(grid[cur_R][cur_C] - grid[next_R][next_C]))) {
                visited[next_R][next_C] = true;
                q.push({next_R, next_C});
            }
        }
    } 

}

void findAnswer() {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < selected_cities.size(); i++) {
        int r = selected_cities[i].first;
        int c = selected_cities[i].second;
        if (!visited[r][c]) BFS(r, c);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) result++;
        }
    }

    answer = max(answer, result);
}

void solve(int idx) {
    if (selected_cities.size() == k) {
        findAnswer();
        return;
    }

    if (idx >= n * n) return;

    int row = idx / n;
    int col = idx % n;

    selected_cities.push_back({row, col});
    solve(idx + 1);
    selected_cities.pop_back();
    solve(idx + 1);
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    solve(0);

    cout << answer << '\n';

    return 0;
}
