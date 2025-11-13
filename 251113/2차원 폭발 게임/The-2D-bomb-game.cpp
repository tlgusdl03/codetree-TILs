#include <iostream>

using namespace std;

int N, M, K;
int numbers_2d[100][100];

void erase(int startIdx, int endIdx, int j) {
    for (int i = startIdx; i <= endIdx; i++) {
        numbers_2d[i][j] = 0;
    }
}

void fall(){
    for (int j = 0; j < N; j++) {
        int idx = N - 1;
        int temp[100] = {0, };
        for (int i = N - 1; i >= 0; i--) {
            if (numbers_2d[i][j] != 0) {
                temp[idx] = numbers_2d[i][j];
                idx--;
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            numbers_2d[i][j] = temp[i];
        }
    }
}

void bomb() {
    while (true) {
        bool pass = true;

        for (int j = 0; j < N; j++) {
        int firstIdx = 0;
        int length = 0;

        for (int i = 0; i < N; i++) {
            if (numbers_2d[i][j] != 0 && numbers_2d[firstIdx][j] == numbers_2d[i][j]) {
                length++;
            }
            else if (numbers_2d[firstIdx][j] != numbers_2d[i][j]) {
                if (length >= M) {
                    erase(firstIdx, i - 1, j);
                    pass = false;
                }
                firstIdx = i;
                length = 1;
            }
        }
            if (length >= M) {
                erase(firstIdx, N - 1, j);
                pass = false;
            }
        }

        fall();

        if (pass) break;
    }
}

void rotate() {
    int temp[100][100] = {0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[j][N - i - 1] = numbers_2d[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            numbers_2d[i][j] = temp[i][j];
        }
    }

    fall();
}

void solve() {
    for (int i = 0; i < K; i++) {
        bomb();
        rotate();
    }

    bomb();
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers_2d[i][j];
        }
    }

    solve();

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (numbers_2d[i][j] != 0) {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}
