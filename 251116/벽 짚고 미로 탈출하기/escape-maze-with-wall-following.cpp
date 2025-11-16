#include <iostream>

using namespace std;

int N;
int x, y;
char grid[101][101];

bool isInRange(int x, int y) {
    return (0 < x && x <= N && 0 < y && y <= N);
}

bool isBlocked(int x, int y, int dir) {
    int target_X = x;
    int target_Y = y;

    if (dir == 0) {
        target_X--;
    }
    else if (dir == 1) {
        target_Y++;
    }
    else if (dir == 2) {
        target_X++;
    }
    else if (dir == 3) {
        target_Y--;
    }

    if (grid[target_X][target_Y] == '#') {
        return true;
    }
    else {
        return false;
    }
}

bool isThereWallIsOnYourRightSide(int x, int y, int dir) {
    int target_X = x;
    int target_Y = y;

    if (dir == 0) {
        target_Y++;
    }
    else if (dir == 1) {
        target_X++;
    }
    else if (dir == 2) {
        target_Y--;
    }
    else if (dir == 3) {
        target_X--;
    }

    if (grid[target_X][target_Y] == '#') {
        return true;
    }
    else {
        return false;
    }
}


// 1. 현재 위치가 격자 밖이라면 종료
// 2. 현재 방향으로 진행할 수 있는지 확인
// 2.1 진행할 수 없다면 방향을 반시계방향으로 90도 회전
// 2.2 진행할 수 있다면 한칸 진행
// 2.3 진행한 후 자신의 현재 위치와 방향을 기준으로 오른쪽에 벽이 있는지 확인
// 2.4 벽이 없다면 방향을 시계방향으로 90도 회전이후 한칸 전진
// 3. 현재 위치가 초기위치와 같다면 탈출 불가능

int solve(int x, int y) {
    int count = 0;
    int dir = 1;
    int cur_X = x;
    int cur_Y = y;

    while (true) {
        int next_X = cur_X;
        int next_Y = cur_Y;

        if (!isBlocked(cur_X, cur_Y, dir)) {
            if (dir == 0) next_X--;
            else if (dir == 1) next_Y++;
            else if (dir == 2) next_X++;
            else if (dir == 3) next_Y--;

            if (!isInRange(next_X, next_Y)) return count + 1;

            if (!isThereWallIsOnYourRightSide(next_X, next_Y, dir)) {
                if (dir == 0) {
                    cur_Y++;
                }
                else if (dir == 1) {
                    cur_X++;
                }
                else if (dir == 2) {
                    cur_Y--;
                }
                else if (dir == 3) {
                    cur_X--;
                }

                dir = (dir + 1) % 4;
            }

            cur_X = next_X;
            cur_Y = next_Y;
            count++;

            if (cur_X == x && cur_Y == y) return -1;
        }
        else {
            dir = (dir - 1 + 4) % 4;
        }
    }

    return count;
}

int main() {
    cin >> N;
    cin >> x >> y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    cout << solve(x, y);

    return 0;
}
