#include <iostream>
#include <vector>
using namespace std;

int T;
int N, M;
int x[2500];
int y[2500];
char d[2500];
bool able[2500];


bool isInRange(int x, int y) {
    return (0 < x && x <= N && 0 < y && y <= N);
}

void directionChange(int i) {
    if (d[i] == 'U') {
        d[i] = 'D';
    }
    else if (d[i] == 'D') {
        d[i] = 'U';
    }
    else if (d[i] == 'R') {
        d[i] = 'L';
    }
    else if (d[i] == 'L') {
        d[i] = 'R';
    }
}

int move() {
    for (int time = 0; time < 2 * N + 1; time++) {
        vector<int> temp[51][51];

        for (int i = 0; i < M; i++) {
            if (!able[i]) continue;

            char dir = d[i];

            int next_X = x[i];
            int next_Y = y[i];

            if (dir == 'U') {
                next_X--;
            }
            else if (dir == 'D') {
                next_X++;
            }
            else if (dir == 'R') {
                next_Y++;
            }
            else if (dir == 'L') {
                next_Y--;
            }

            if (!isInRange(next_X, next_Y)) {
                directionChange(i);
            }
            else {
                x[i] = next_X;
                y[i] = next_Y;
            }

            temp[x[i]][y[i]].push_back(i);
        }

        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= N; col++) {
                if (temp[row][col].size() >= 2) {
                    while(!temp[row][col].empty()) {
                        int idx = temp[row][col].back();
                        temp[row][col].pop_back();
                        able[idx] = false;
                    }
                }
            }
        }

    }

    int result = 0;

    for (int i = 0; i < M; i++) {
        if (able[i]) result++;
    }

    return result;
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> x[i] >> y[i] >> d[i];
            able[i] = true;
        }

        cout << move() << '\n';
    }

    return 0;
}
