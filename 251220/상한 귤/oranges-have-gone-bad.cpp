#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
int step[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
vector<pair<int, int>> rotten;

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void push(int row, int col, int time) {
    visited[row][col] = true;
    q.push({row, col});
    step[row][col] = time;
    return;
}

void BFS() {
    for (int i = 0; i < rotten.size(); i++) {
        int r = rotten[i].first;
        int c = rotten[i].second;
        push(r, c, 0);
    }

    while(!q.empty()) {
        int cur_R = q.front().first;
        int cur_C = q.front().second;
        int cur_T = step[cur_R][cur_C];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_R = cur_R + dx[i];
            int next_C = cur_C + dy[i];

            if (isInRange(next_R, next_C) && !visited[next_R][next_C] && grid[next_R][next_C]) {
                int next_T = cur_T + 1;
                push(next_R, next_C, next_T);
            }
        }
    }
}

void printAnswer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) cout << -1 << " ";
            else if (grid[i][j] == 1 && step[i][j] == 0) cout << -2 << " ";
            else cout << step[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                rotten.push_back({i, j});
            }
        }
    }

    BFS();
    printAnswer();

    return 0;
}
