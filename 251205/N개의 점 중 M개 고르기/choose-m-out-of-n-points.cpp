#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int x[20], y[20];
bool flag[20];
int result = INT_MAX;

void solve(int idx, int cnt) {
    if (cnt == m) {
        int max_Distance = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (flag[i] && flag[j]) {
                    int temp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                    max_Distance = max(max_Distance, temp);
                }
            }
        }

        result = min(result, max_Distance);
        return;
    }

    if (idx >= n) return;

    solve(idx + 1, cnt);

    flag[idx] = true;

    solve(idx + 1, cnt + 1);

    flag[idx] = false;
    
    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    solve(0, 0);

    cout << result << '\n';

    return 0;
}
