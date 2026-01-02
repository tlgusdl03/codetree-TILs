#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int coin[100];
int dp[101];
int ans = -1;

void init() {
    for (int i = 0; i <= 100; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
}

void solve() {
    init();

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) continue;

            for (int k = 0; k < N; k++) {
                if (j + coin[k] == i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
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
