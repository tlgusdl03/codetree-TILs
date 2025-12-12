#include <iostream>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int MAX_BLOCK = 0;
int BOMB_COUNT = 0;
int TEMP_COUNT = 0;

bool isInRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

void DFS(int x, int y) {
    visited[x][y] = true;
    TEMP_COUNT++;

    for (int i = 0; i < 4; i++) {
        int next_X = x + dx[i];
        int next_Y = y + dy[i];

        if (isInRange(next_X, next_Y) 
        && !visited[next_X][next_Y] 
        && grid[x][y] == grid[next_X][next_Y]) {
            DFS(next_X, next_Y);
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                TEMP_COUNT = 0;
                DFS(i, j);
                if (4 <= TEMP_COUNT) BOMB_COUNT++;
                if (MAX_BLOCK < TEMP_COUNT) MAX_BLOCK = TEMP_COUNT;
            }
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    solve();

    cout << BOMB_COUNT << " " << MAX_BLOCK << '\n';

    return 0;
}
