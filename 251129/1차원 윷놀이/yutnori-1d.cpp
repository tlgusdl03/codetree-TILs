#include <iostream>

using namespace std;

int n, m, k;
int nums[12];
int location[4];
int result = 0;

int calc() {
    int temp = 0;
    for (int i = 0; i < k; i++) {
        if (location[i] >= m) temp++;
    }
    return temp;
}

void solve(int idx) {

    result = max(result, calc());

    if (idx == n) return;
    
    
    for (int i = 0; i < k; i++) {
        if (location[i] >= m) continue;
        
        location[i] += nums[idx];
        solve(idx + 1);
        location[i] -= nums[idx];
    }
    
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < k; i++) {
        location[i] = 1;
    }

    solve(0);

    cout << result << '\n';

    return 0;
}
