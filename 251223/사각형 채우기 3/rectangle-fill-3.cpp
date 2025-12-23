#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1000;

long long tb[MAX_N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    tb[0] = 1;
    tb[1] = 2;
    tb[2] = 7;

    for (int i = 3; i <= n; i++) {
        long long temp = 0;
        for (int j = 0; j <= i - 3; j++) {
            temp = (temp + tb[j] * 2) % MOD;  // 누적합 2 * sum(dp[0..i-3])
        }
        tb[i] = ( (tb[i - 1] * 2) % MOD
                + (tb[i - 2] * 3) % MOD
                + temp ) % MOD;
    }

    cout << tb[n];
    return 0;
}
