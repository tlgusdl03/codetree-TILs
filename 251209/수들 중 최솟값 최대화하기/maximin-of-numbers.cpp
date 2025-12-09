#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n;
int grid[10][10];
bool visited_Row[10];
bool visited_Col[10];
int answer = 0;
vector<int> nums;

void solve(int cnt, int row) { 
    if (cnt == n) {
        int min_Num = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            min_Num = min(min_Num, nums[i]);
        }
        answer = max(answer, min_Num);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited_Row[row] || visited_Col[i]) continue;
        visited_Row[row] = true;
        visited_Col[i] = true;
        nums.push_back(grid[row][i]);
        solve(cnt + 1, row + 1);

        visited_Row[row] = false;
        visited_Col[i] = false;
        nums.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    solve(0, 0);

    cout << answer << '\n';

    return 0;
}
