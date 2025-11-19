#include <iostream>

using namespace std;

int n;
int grid[101][101];

bool isInRange(int x, int y) {
    return (0 < x && x <= n && 0 < y && y <= n);
}

int meet_1_block(int dir) {
    // 아래 -> 왼쪽
    if (dir == 0) {
        return 1;
    }
    // 왼 -> 아래
    else if (dir == 1) {
        return 0;
    }
    // 위 -> 오른쪽
    else if (dir == 2) {
        return 3;
    }
    // 오른쪽 -> 위
    else if (dir == 3) {
        return 2;
    }
}

int meet_2_block(int dir) {
    if (dir == 0) {
        return 3;
    }
    else if (dir == 1) {
        return 2;
    }
    else if (dir == 2) {
        return 1;
    }
    else if (dir == 3) {
        return 0;
    }
}

int move(int start_X, int start_Y, int dir) {
    int result = 0;

    int cur_X = start_X;
    int cur_Y = start_Y;

    int next_X = cur_X;
    int next_Y = cur_Y;
    int next_dir = dir;

    while (true) {
        result++;

        if (dir == 0) {
            next_X++;
        }
        else if (dir == 1) {
            next_Y--;
        }
        else if (dir == 2) {
            next_X--;
        }
        else if (dir == 3) {
            next_Y++;
        }

        if (!isInRange(next_X, next_Y)) return result;

        if (grid[next_X][next_Y] == 1) {
            next_dir = meet_1_block(dir);
        }
        else if (grid[next_X][next_Y] == 2) {
            next_dir = meet_2_block(dir);
        }

        cur_X = next_X;
        cur_Y = next_Y;
        dir = next_dir;
    }
}

int solve() {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result = max(result, move(0, i, 0));
    }

    for (int i = 1; i <= n; i++) {
        result = max(result, move(i, n + 1, 1));
    }

    for (int i = 1; i <= n; i++) {
        result = max(result, move(n + 1, i, 2));
    }

    for (int i = 1; i <= n; i++) {
        result = max(result, move(i, 0, 3));
    }

    return result;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];

    cout << solve();

    return 0;
}
