#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int grid[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[50][50];
int MAX_K = 1;
int MAX_Count = 0;
int count = 0;

bool isInRange(int x, int y) {
    return (0 <= x && x < N
    && 0 <= y && y < M);
}

bool isVisited(int x, int y) {
    return visited[x][y];
}

bool isSafe(int k, int a) {
    return (k < a);
}

void DFS(int row, int col, int k) {
    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        int next_Row = row + dx[i];
        int next_Col = col + dy[i];

        if (isInRange(next_Row, next_Col) && isSafe(k, grid[next_Row][next_Col]) && !isVisited(next_Row, next_Col)) {
            DFS(next_Row, next_Col, k);
        }
    }
}

void solve() {
    for (int k = 1; k <= 100; k++) {
        memset(visited, false, sizeof(visited));
        count = 0;  
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!isVisited(i, j) && isSafe(k, grid[i][j])) {
                    count++;
                    DFS(i, j, k);
                }
            }
        }
        if (MAX_Count < count) {
            MAX_Count = count;
            MAX_K = k;
        }
    }
    
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    solve();

    cout << MAX_K << " " << MAX_Count << '\n';

    return 0;
}
