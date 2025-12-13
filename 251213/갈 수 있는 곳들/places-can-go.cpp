#include <iostream>
#include <queue>
using namespace std;

int n, k;
int grid[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int calAnswer () {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j]) answer++;
        }
    }
    return answer;
}

bool isInRange(int row, int col) {
    return (0 < row && row <= n && 0 < col && col <= n);
}

void BFS(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while(!q.empty()) {
        int cur_Row = q.front().first;
        int cur_Col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_Row = cur_Row + dx[i];
            int next_Col = cur_Col + dy[i];

            if (isInRange(next_Row, next_Col) 
            && !visited[next_Row][next_Col] 
            && grid[next_Row][next_Col] == 0) {
                q.push({next_Row, next_Col});
                visited[next_Row][next_Col] = true;
            }
        }

    }
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;

        if (!visited[r][c] && grid[r][c] == 0) BFS(r, c);
    }

    cout << calAnswer() << '\n';
    
    return 0;
}
