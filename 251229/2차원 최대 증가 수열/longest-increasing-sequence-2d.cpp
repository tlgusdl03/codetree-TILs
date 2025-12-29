#include <iostream>
#include <climits>
using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];
int ans = 0;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 1;
}

void solve() {
    init();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < j; l++) {
                    if (dp[k][l] == INT_MIN) continue;
                    if (grid[k][l] < grid[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[k][l] + 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    solve();

    cout << ans << '\n';

    return 0;
}
