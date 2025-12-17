#include <iostream>
#include <queue>
using namespace std;

int n;
int r1, c1, r2, c2;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool visited[100][100];
int step[100][100];
queue<pair<int, int>> q;

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void push(int row, int col, int dis) {
    step[row][col] = dis;
    visited[row][col] = true;
    q.push({row, col});
}

void BFS(int row, int col) {
    push(row, col, 0);

    while(!q.empty()) {
        int cur_R = q.front().first;
        int cur_C = q.front().second;
        int cur_D = step[cur_R][cur_C];
        q.pop();

        if (cur_R == r2 && cur_C == c2) return;

        for (int i = 0; i < 8; i++) {
            int next_R = cur_R + dx[i];
            int next_C = cur_C + dy[i];

            if (isInRange(next_R, next_C) && !visited[next_R][next_C]) {
                int next_D = step[cur_R][cur_C] + 1;
                push(next_R, next_C, next_D);
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            step[i][j] = -1;
            visited[i][j] = false;
        }
    }
    
    BFS(r1, c1);

    if (step[r2][c2] == -1) {
        cout << -1 << '\n';
    }
    else {
        cout << step[r2][c2] << '\n';
    }

    return 0;
}
