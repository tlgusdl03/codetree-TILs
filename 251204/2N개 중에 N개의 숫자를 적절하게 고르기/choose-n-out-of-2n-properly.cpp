#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int num[20];
bool flag[20];
int result = INT_MAX;

void solve(int idx, int cnt) {
    if (cnt == n) {
        int sum_A = 0;
        int sum_B = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (flag[i]) sum_A += num[i];
            else sum_B += num[i];
        }

        result = min(result, abs(sum_A - sum_B));
    }

    if (idx >= 2 * n) return;

    flag[idx] = true;
    solve(idx + 1, cnt + 1);

    flag[idx] = false;
    solve(idx + 1, cnt);

    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }

    solve(0, 0);

    cout << result << '\n';

    return 0;
}
