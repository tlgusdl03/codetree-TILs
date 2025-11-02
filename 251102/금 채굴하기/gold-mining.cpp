#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int grid[20][20];


int findSum(int x, int y, int n, int m) {
    int result = 0;

    for (int k = 0; k <= n; k++) {
        int temp = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (abs(x - i) + abs(y - j) <= k) temp += grid[i][j];
            }
        }
        if (temp * m >= pow(k, 2) + pow((k + 1), 2)) {
            result = max(result, temp);
        }
    }

    return result;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, findSum(i, j, n, m));
        }
    }

    cout << result;
    return 0;
}
