#include <iostream>

using namespace std;

char board[10][10];

int main() {

    int L_pos[2];
    int R_pos[2];
    int B_pos[2];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'L') {
                L_pos[0] = i;
                L_pos[1] = j;
            }
            else if (board[i][j] == 'R') {
                R_pos[0] = i;
                R_pos[1] = j;
            }
            else if (board[i][j] == 'B') {
                B_pos[0] = i;
                B_pos[1] = j;
            }
        }
    }

    // L B R이 같은 행, 열에 있는 경우 +2를
    // L B R이 다른 행, 열에 있는 경우 가로 + 세로

    int result = 0;

    if (L_pos[0] == R_pos[0] && L_pos[0] == B_pos[0] && R_pos[0] == B_pos[0]) {
        if (L_pos[1] < R_pos[1] && R_pos[1] < B_pos[1] || L_pos[1] > R_pos[1] && R_pos[1] > B_pos[1]) {
            result = abs(B_pos[1] - L_pos[1]) + 1;
        }
        else {
            result = abs(B_pos[1] - L_pos[1]) - 1;
        }
    }
    else if (L_pos[1] == R_pos[1] && L_pos[1] == B_pos[1] && R_pos[1] == B_pos[1]) {
        if (L_pos[0] < R_pos[0] && R_pos[0] < B_pos[0] || L_pos[0] > R_pos[0] && R_pos[0] > B_pos[0]) {
            result = abs(B_pos[0] - L_pos[0]) + 1;
        }
        else {
            result = abs(B_pos[0] - L_pos[0]) - 1;
        }
    }
    else {
        result = abs(B_pos[0] - L_pos[0]) + abs(B_pos[1] - L_pos[1]) - 1;
    }

    cout << result;

    return 0;
}