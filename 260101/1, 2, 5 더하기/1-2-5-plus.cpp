#include <iostream>
#include <climits>
using namespace std;

int n;
int ans = 0;
int dp[1001];

void init() {
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
}

void solve() {
    init();

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {

            if (j + 1 == i) {
                dp[i] = (dp[i] + dp[j]) % 10007;
            }
            else if (j + 2 == i) {
                dp[i] = (dp[i] + dp[j]) % 10007;
            }
            else if (j + 5 == i) {
                dp[i] = (dp[i] + dp[j]) % 10007;
            }
        }
    }

    ans = dp[n];
}

int main() {
    cin >> n;

    solve();

    cout << ans << '\n';

    return 0;
}
