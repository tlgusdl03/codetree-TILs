#include <iostream>
#include <string>

using namespace std;

string tempInput[3];
int inp[3][3];

bool getResult (int a, int b, int c, int m, int n) {
    return ((a == m || a == n) && (b == m || b == n) && (c == m || c == n) && !(a == b && b == c && a == c));
}

int main() {
    for (int i = 0; i < 3; i++) cin >> tempInput[i];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inp[i][j] = tempInput[i][j] - '0';
        }
    }

    int result = 0;

    for (int i = 1; i <= 8; i++) {
        for (int j = i + 1; j <= 9; j++) {
            bool pass = false;

            for (int k = 0; k < 3; k++) {
                if (getResult(inp[k][0], inp[k][1], inp[k][2], i, j)) {
                    pass = true;
                    break;
                }
                else if (getResult(inp[0][k], inp[1][k], inp[2][k], i, j)) {
                    pass = true;
                    break;
                }
            }

            if (getResult(inp[0][0], inp[1][1], inp[2][2], i, j)) {
                pass = true;
            }
            else if (getResult(inp[0][2], inp[1][1], inp[2][0], i, j)) {
                pass = true;
            }

            if (pass) result++;
        }
    }

    cout << result;

    return 0;
}