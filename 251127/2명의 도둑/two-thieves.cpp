#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c;
int weight[10][10];
bool flag[10];
int result = 0;

int findMax(int row, int col, int idx, int total_weight, int total_price) {
    if (idx == m) {
        return total_price;
    }
    
    int exclude = findMax(row, col, idx + 1, total_weight, total_price);
    int include = 0;

    int w = weight[row][col + idx];
    if (total_weight + w <= c) {
        include = findMax(row, col, idx + 1, total_weight + w, total_price + w * w);
    }

    return max(include, exclude);
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = 0; l <= n - m; l++) {
                    if (k == i && l < j + m) continue;
                    int result1 = findMax(i, j, 0, 0, 0);
                    int result2 = findMax(k, l ,0, 0, 0);

                    result = max(result, result1 + result2);
                }
            }
        }
    }
}
int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    solve();

    cout << result << '\n';

    return 0;
}