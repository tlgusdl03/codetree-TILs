#include <iostream>
#include <cstring>
using namespace std;

int n;
int m = 0;
int grid[20][20];
int dx1[4] = {-2, -1, 1, 2};
int dy1[4] = {0, 0, 0, 0};
int dx2[4] = {-1, 0, 1, 0};
int dy2[4] = {0, 1, 0, -1};
int dx3[4] = {-1, -1, 1, 1};
int dy3[4] = {-1, 1, 1, -1};

bool result[20][20] = {false, };

int bombs[20];
int sum = 0;

bool isInRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

void solve(int idx) {
    if (idx == m) {
        
        memset(result, false, sizeof(result));

        int bomb_idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result[i][j] = true;

                    for (int k = 0; k < 4; k++) {
                        int cur_X = i;
                        int cur_Y = j;

                        if (bombs[bomb_idx] == 1) {
                            cur_X += dx1[k];
                            cur_Y += dy1[k];
                        }
                        else if (bombs[bomb_idx] == 2) {
                            cur_X += dx2[k];
                            cur_Y += dy2[k];
                        }
                        else if (bombs[bomb_idx] == 3) {
                            cur_X += dx3[k];
                            cur_Y += dy3[k];
                        }

                        if (isInRange(cur_X, cur_Y)) {
                            result[cur_X][cur_Y] = true;
                        }
                    }
                    bomb_idx++;
                }
            }
        }

        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (result[i][j]) temp++;
            }
        }

        sum = max(sum, temp);
        
        return;
    }

    for (int i = 1; i <= 3; i++) {
        bombs[idx] = i;
        solve(idx + 1);
    }

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                m++;
            }
        }
    }

    solve(0);

    cout << sum << '\n';

    return 0;
}
