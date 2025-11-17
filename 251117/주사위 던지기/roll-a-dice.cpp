#include <iostream>

using namespace std;

int n, m;
int r, c;
char directions[10000];
int result[100][100] = {0, };

// {top, bottom, right, left, front, back}
int dice[6] = {1, 6, 3, 4, 2, 5};

// left <- top, top <- right, right <- bottom, bottom <- left
void rollLeft() {
    int temp = dice[3];
    dice[3] = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = temp;
}

// front <- top, top <- back, back <- bottom, bottom <- front
void rollDown() {
    int temp = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = temp;
}

// top -> right, right -> bottom, bottom -> left, left -> top
void rollRight() {
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = temp;
}

// top -> back, back -> bottom, bottom -> front, front -> top
void rollUp() {
    int temp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[5];
    dice[5] = temp;
}

bool isInRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

void next_Num(char dir) {
    if (dir == 'L') {
        rollLeft();
    }
    else if (dir == 'D') {
        rollDown();
    }
    else if (dir == 'R') {
        rollRight();
    }
    else if (dir == 'U') {
        rollUp();
    }
}

void move() {
    int cur_X = r - 1;
    int cur_Y = c - 1;
    int top = dice[0];
    int bottom = dice[1];

    result[cur_X][cur_Y] = bottom;

    for (int i = 0; i < m; i++) {
        int next_X = cur_X;
        int next_Y = cur_Y;

        if (directions[i] == 'L') {
            next_Y--;
        }
        else if (directions[i] == 'D') {
            next_X++;
        }
        else if (directions[i] == 'R') {
            next_Y++;
        }
        else if (directions[i] == 'U') {
            next_X--;
        }

        if (isInRange(next_X, next_Y)) {
            cur_X = next_X;
            cur_Y = next_Y;

            next_Num(directions[i]);
            bottom = dice[1];

            result[cur_X][cur_Y] = bottom;
        }
    }
}

void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> m >> r >> c;

    for (int i = 0; i < m; i++) {
        cin >> directions[i];
    }

    move();

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count += result[i][j];
        }
    }

    // debug();
    cout << count;

    return 0;
}
