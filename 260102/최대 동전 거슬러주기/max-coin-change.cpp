#include <iostream>
#include <algorithm>
#include <climits>
#define M_MAX 10000
using namespace std;

int N, M;
int coin[100];
int dp[M_MAX + 1];
int ans = -1;

void init() {
    for (int i = 0; i <= M_MAX; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
}

void solve() {
    init();

    for (int i = 1; i <= M; i++) {
        for (int k = 0; k < N; k++) {
            if (i < coin[k] || dp[i - coin[k]] == INT_MIN) continue;

            dp[i] = max(dp[i], dp[i - coin[k]] + 1);
        }
    }

    if (dp[M] != INT_MIN) ans = dp[M];
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    solve();

    cout << ans << '\n';

    return 0;
}
