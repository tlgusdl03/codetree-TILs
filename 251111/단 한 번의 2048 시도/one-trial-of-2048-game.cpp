#include <iostream>

using namespace std;

int grid[4][4];
char dir;

void aggregate(char dir) {
    if (dir == 'L') {
        for (int i = 0; i < 4; i++) {
            int lastIdx = 0;
            for (int j = 1; j < 4; j++) {
                if (grid[i][lastIdx] == grid[i][j]) {
                    grid[i][lastIdx] *= 2;
                    grid[i][j] = 0;
                    lastIdx = j;
                }
                else if (grid[i][lastIdx] != grid[i][j] && grid[i][j] != 0) {
                    lastIdx = j;
                }
            } 
        }
    } 

    else if (dir == 'R') {
        for (int i = 0; i < 4; i++) {
            int lastIdx = 3;
            for (int j = 2; j >= 0; j--) {
                if (grid[i][lastIdx] == grid[i][j]) {
                    grid[i][lastIdx] *= 2;
                    grid[i][j] = 0;
                    lastIdx = j;
                }
                else if (grid[i][lastIdx] != grid[i][j] && grid[i][j] != 0) {
                    lastIdx = j;
                }
            } 
        }
    }

    else if (dir == 'U') {
        for (int j = 0; j < 4; j++) {
            int lastIdx = 0;
            for (int i = 1; i < 4; i++) {
                if (grid[lastIdx][j] == grid[i][j]) {
                    grid[lastIdx][j] *= 2;
                    grid[i][j] = 0;
                    lastIdx = i;
                }
                else if (grid[lastIdx][j] != grid[i][j] && grid[i][j] != 0) {
                    lastIdx = i;
                }
            }
        }
    } 

    else if (dir == 'D') {
        for (int j = 0; j < 4; j++) {
            int lastIdx = 3;
            for (int i = 2; i >= 0; i--) {
                if (grid[lastIdx][j] == grid[i][j]) {
                    grid[lastIdx][j] *= 2;
                    grid[i][j] = 0;
                    lastIdx = i;
                }
                else if (grid[lastIdx][j] != grid[i][j] && grid[i][j] != 0) {
                    lastIdx = i;
                }
            }
        }
    }
}

void move(char dir) {
    if (dir == 'L') {
        for (int i = 0; i < 4; i++) {
            int idx = 0;
            int temp[4] = {0, };

            for (int j = 0; j < 4; j++) {
                if (grid[i][j] != 0) {
                    temp[idx] = grid[i][j];
                    idx++;
                }
            }

            for (int j = 0; j < 4; j++) {
                grid[i][j] = temp[j];
            }
        }
    }
    
    else if (dir == 'R') {
        for (int i = 0; i < 4; i++) {
            int idx = 3;
            int temp[4] = {0, };

            for (int j = 3; j >= 0; j--) {
                if (grid[i][j] != 0) {
                    temp[idx] = grid[i][j];
                    idx--;
                }
            }

            for (int j = 3; j >=0; j--) {
                grid[i][j] = temp[j];
            }
        }
    }

    else if (dir == 'U') {
        for (int j = 0; j < 4; j++) {
            int idx = 0;
            int temp[4] = {0, };

            for (int i = 0; i < 4; i++) {
                if (grid[i][j] != 0) {
                    temp[idx] = grid[i][j];
                    idx++;
                }
            }

            for (int i = 0; i < 4; i++) {
                grid[i][j] = temp[i];
            }
        }
    }

    else if (dir == 'D') {
        for (int j = 0; j < 4; j++) {
            int idx = 3;
            int temp[4] = {0, };

            for (int i = 3; i >= 0; i--) {
                if (grid[i][j] != 0) {
                    temp[idx] = grid[i][j];
                    idx--;
                }
            }

            for (int i = 3; i >= 0; i--) {
                grid[i][j] = temp[i];
            }
        }
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;

    aggregate(dir);
    move(dir);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
