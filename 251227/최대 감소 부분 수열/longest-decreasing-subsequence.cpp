#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_N = 1000;
int ans = 0;

int N;
int M[MAX_N];
int dp[MAX_N];

void init() {
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
    }
}

void solve() {
    init();
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) continue;
            
            if (M[j] > M[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    solve();

    cout << ans << '\n';

    return 0;
}
