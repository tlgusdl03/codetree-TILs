#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int num[10];
int result = INT_MAX;

void solve(int idx, int hop) {
    if (idx >= n - 1) {
        result = min(result, hop);
        return;
    }

    int max_Hop = num[idx];

    for (int i = 0; i <= max_Hop; i++) {
        int next_Idx = idx + i;

        if (next_Idx > idx) {
            solve(next_Idx, hop + 1);
        }
    }

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    solve(0, 0);

    if (result == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << result << '\n';
    }

    return 0;
}
