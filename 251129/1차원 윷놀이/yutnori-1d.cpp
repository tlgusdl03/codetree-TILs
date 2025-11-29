#include <iostream>

using namespace std;

int n, m, k;
int nums[12];
int location[4] = {0, };
int result = 0;

void solve(int idx) {

    int temp = 0;
    for (int i = 0; i < k; i++) {
        if (location[i] >= m - 1) {
            temp++;
        }
    }

    result = max(result, temp);

    if (idx == n) {
        return;
    }
    else {
        for (int i = 0; i < k; i++) {
            if (location[i] < m - 1) {
                location[i] += nums[idx];

                solve(idx + 1);

                location[i] -= nums[idx];
            }
        }
    }
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    solve(0);

    cout << result << '\n';

    return 0;
}
