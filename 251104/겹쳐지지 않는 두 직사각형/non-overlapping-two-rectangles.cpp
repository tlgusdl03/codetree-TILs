#include <iostream>

using namespace std;

int n, m;
int grid[5][5];

bool isOverlapped(int x1_A, int y1_A, int x2_A, int y2_A, int x1_B, int y1_B, int x2_B, int y2_B) {
    return !(x1_B > x2_A || x2_B < x1_A || y1_B > y2_A || y2_B < y1_A);
}

int findSum(int x1, int y1, int x2, int y2) {
    int result = 0;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            result += grid[i][j];
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

    int result = -10000001;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    for (int o = 0; o < n; o++) {
                        for (int p = 0; p < m; p++) {
                            for (int q = 0; q < n; q++) {
                                for (int r = 0; r < m; r++) {
                                    int x1_A = min(i, k);
                                    int y1_A = min(j, l);
                                    int x2_A = max(i, k);
                                    int y2_A = max(j, l);

                                    int x1_B = min(o, q);
                                    int y1_B = min(p, r);
                                    int x2_B = max(o, q);
                                    int y2_B = max(p, r);

                                    if (isOverlapped(x1_A, y1_A, x2_A, y2_A, x1_B, y1_B, x2_B, y2_B)) continue;

                                    int temp = findSum(x1_A, y1_A, x2_A, y2_A) + findSum(x1_B, y1_B, x2_B, y2_B);

                                    result = max(result, temp);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}
