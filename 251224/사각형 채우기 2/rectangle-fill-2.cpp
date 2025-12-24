#include <iostream>
#define MAX_N 1000
#define MOD_N 10007
using namespace std;

int n;
int dp[MAX_N + 1];
int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= MAX_N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD_N;
    }

    cout << dp[n] << '\n';

    return 0;
}
