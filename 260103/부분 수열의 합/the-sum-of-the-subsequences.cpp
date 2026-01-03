#include <iostream>
#include <climits>
#define M_MAX 10000
#define N_MAX 100
using namespace std;

int n, m;
int A[N_MAX + 1];
bool dp[N_MAX + 1][M_MAX + 1];

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = false;
        }
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
}

void solve() {
    init();

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i >= A[j] && dp[j - 1][i - A[j]]) || dp[j - 1][i]) dp[j][i] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    solve();

    (dp[n][m])?(cout << "Yes" << '\n'):(cout << "No" << '\n');

    return 0;
}
