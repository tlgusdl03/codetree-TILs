#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Job {
    int s, e, p;
};

int N;
Job jobs[1000];
int dp[1000];
int ans = 0;

void init() {
    for (int i = 0; i < N; i++) {
        dp[i] = jobs[i].p;
    }
}

void solve() {
    init();

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) continue;

            if (jobs[j].e < jobs[i].s) {
                dp[i] = max(dp[i], dp[j] + jobs[i].p);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        jobs[i] = {s, e, p};
    }

    solve();

    cout << ans << '\n';

    return 0;
}
