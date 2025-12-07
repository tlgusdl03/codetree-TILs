#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[10][10];
bool visited_Row[10];
bool visited_Col[10];
vector<pair<int, int>> selected;
int result = 0;

int getResult() {
    int sum = 0;
    for (int i = 0; i < selected.size(); i++) {
        int row = selected[i].first;
        int col = selected[i].second;

        sum += grid[row][col];
    }

    return sum;
}

void solve(int cnt) {
    if (cnt == n) {
        result = max(result, getResult());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited_Row[i] || visited_Col[j]) continue;

            selected.push_back({i, j});
            visited_Row[i] = true;
            visited_Col[j] = true;
            solve(cnt + 1);

            selected.pop_back();
            visited_Row[i] = false;
            visited_Col[j] = false;
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

    solve(0);

    cout << result << '\n';

    return 0;
}
