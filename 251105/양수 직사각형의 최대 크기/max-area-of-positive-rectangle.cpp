#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int findSum(int x1, int y1, int x2, int y2) {
    int result = 0;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (grid[i][j] < 0) {
                return -1;
            }
            result++;
        }
    }

    return result;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    int x1 = min(i, k);
                    int y1 = min(j, l);
                    int x2 = max(i, k);
                    int y2 = max(j, l);
                    
                    result = max(result, findSum(x1, y1, x2, y2));
                }
            }
        }
    }

    cout << result;

    return 0;
}
