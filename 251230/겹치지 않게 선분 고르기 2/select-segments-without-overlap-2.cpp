#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Line {
    int x1, x2;
};

int n;
Line lines[1000];
int dp[1000];
int ans = 0;


void init() {
    sort(lines, lines + n, [](const Line& a, const Line& b){
        if (a.x2 == b.x2) return a.x1 < b.x1;
        return a.x2 < b.x2;
    });

    for (int i = 0; i < n; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 1;
}

void solve() {
    init();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) continue;

            if (lines[j].x2 < lines[i].x1) {
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
        int x1, x2;
        cin >> x1 >> x2;
        lines[i] = {x1, x2};
    }

    solve();

    cout << ans << '\n';

    return 0;
}
