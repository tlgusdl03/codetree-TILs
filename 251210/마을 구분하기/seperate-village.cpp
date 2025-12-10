#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
bool visited[25][25];
int town_Num = 0;
vector<int> peoples;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool canGo(int row, int col) {
    return (0 <= row && row < n 
    && 0 <= col && col < n 
    && grid[row][col] == 1 
    && !visited[row][col]);
}

void DFS(int idx, int row, int col) {
    visited[row][col] = true;
    peoples[idx]++;

    for (int i = 0; i < 4; i++) {
        int next_Row = row + dx[i];
        int next_Col = col + dy[i];

        if (canGo(next_Row, next_Col)) {
            DFS(idx, next_Row, next_Col);
        }
    }
}

void solve() {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (canGo(i, j)) {
                town_Num++;
                peoples.push_back(0);
                DFS(idx, i, j);
                idx++;
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
    sort(peoples.begin(), peoples.end());

    cout << town_Num << '\n';
    
    for (int i = 0; i < peoples.size(); i++) {
        cout << peoples[i] << '\n';
    }

    return 0;
}
