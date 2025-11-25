#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int x1[15], x2[15];
bool flag[15] = {false, };
int line[1001] = {0, };
int result = 0;

void choice(int idx, int count) {
    if (idx == n) {
        memset(line, 0, sizeof(line));

        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                for (int j = x1[i]; j <= x2[i]; j++) {
                line[j]++;
                }
            }
        }

        for (int i = 1; i < 1001; i++) {
            if (line[i] > 1) return;
        }

        result = max(result, count);

    }
    else {
        flag[idx] = true;
        choice(idx + 1, count + 1);

        flag[idx] = false;
        choice(idx + 1, count);
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    choice(0, 0);

    cout << result << '\n';

    return 0;
}
