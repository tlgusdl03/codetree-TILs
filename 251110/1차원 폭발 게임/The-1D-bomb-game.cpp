#include <iostream>

using namespace std;

int n, m;
int numbers[100];

void bomb(int startIdx, int endIdx) {
    // cout << startIdx << " " << endIdx << '\n';
    for (int i = startIdx; i <= endIdx; i++) {
        numbers[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    while (true) {
        bool pass = true;
        int firstIdx = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[firstIdx] == numbers[i] && numbers[i] != 0) {
                count++;
            }
            else if (numbers[firstIdx] != numbers[i]) {
                if (count >= m) {
                    bomb(firstIdx, i - 1);
                    pass = false;
                }
                count = 1;
                firstIdx = i;
            }
        }

        if (count >= m) {
            bomb(firstIdx, n - 1);
            pass = false;
        }

        int idx = 0;
        int temp[100] = {0, };

        for (int i = 0; i < n; i++) {
            if (numbers[i] != 0) {
                temp[idx] = numbers[i];
                idx++;
            }
        }

        for (int i = 0; i < n; i++) {
            numbers[i] = temp[i];
        }

        // for (int i = 0; i < n; i++) {
        //     cout << numbers[i] << " ";
        // }
        // cout << '\n';

        if (pass) break;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] != 0) {
            result++;
        }
    }

    cout << result << '\n';

    for (int i = 0; i < n; i++) {
        if (numbers[i] != 0) {
            cout << numbers[i] << '\n';
        }
    }

    return 0;
}
