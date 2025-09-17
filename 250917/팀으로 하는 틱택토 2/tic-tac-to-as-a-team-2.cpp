#include <iostream>
#include <string>

using namespace std;

string tempInput[3];
int inp[3][3];

bool getResult (int a, int b, int c, int m, int n) {
    return (!(a == b && b == c && a == c) && (a == m || a == n) && (b == m || b == n) && (c == m || c == n));
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
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (k == 0) {
                        if (getResult(inp[k][l], inp[k + 1][l], inp[k + 2][l], i, j)) {
                            result++;
                            continue;
                        }
                    }

                    if (l == 0) {
                        if (getResult(inp[k][l], inp[k][l + 1], inp[k][l + 2], i, j)) {
                            result++;
                            continue;
                        }
                    }

                    if (k == 1 && l == 1) {
                        if (getResult(inp[k - 1][l - 1], inp[k][l], inp[k + 1][l + 1], i, j)) {
                            result++;
                            continue;
                        }

                        if (getResult(inp[k - 1][l + 1], inp[k][l], inp[k + 1][l - 1], i, j)) {
                            result++;
                            continue;
                        }
                    }
                }
            }
            
        }
    }

    cout << result;

    return 0;
}