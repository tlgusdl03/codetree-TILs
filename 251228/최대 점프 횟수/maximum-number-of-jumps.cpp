#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[1000];
int dp[1000];
int ans = 0;

void init() {
    for (int i = 0; i < 1000; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
}

void solve() {
    init();

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) continue;
            if (j + arr[j] >= i) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve();

    cout << ans << '\n';

    return 0;
}
