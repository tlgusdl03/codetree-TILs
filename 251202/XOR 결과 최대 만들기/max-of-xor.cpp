#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[20];
int result = 0;

void solve(int idx, int cnt, int curXor) {
    if (idx == n) {
        if (cnt == m) result = max(result, curXor);
        return;
    }

    solve(idx + 1, cnt, curXor);

    solve(idx + 1, cnt + 1, curXor ^ A[idx]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    solve(0, 0, 0);

    cout << result << '\n';

    return 0;
}