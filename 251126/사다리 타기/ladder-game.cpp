#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int h = 0;
int a[15], b[15];
bool flag[15] = {false, };

bool ladder[12][16] = {false, };
int result[16] = {0, };
int min_Result = 16;

void init() {
    for (int ladder_idx = 0; ladder_idx < m; ladder_idx++) {
        int n_idx = a[ladder_idx];
        int m_idx = b[ladder_idx];

        ladder[n_idx][m_idx] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        int pos = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[pos][j]) pos++;
            else if (pos > 1 && ladder[pos - 1][j]) pos--;
        }
        result[pos] = i;
    }
}

void make_choice(int idx, int count) {
    if (idx == m) {
        // flag를 기반으로 ladder 배열 생성
        memset(ladder, false, sizeof(ladder));

        for (int ladder_idx = 0; ladder_idx < m; ladder_idx++) {
            if (flag[ladder_idx]) {
                int n_idx = a[ladder_idx];
                int m_idx = b[ladder_idx];

                ladder[n_idx][m_idx] = true;
            }
        }

        // 생성된 ladder 배열을 시뮬레이션
        int temp[16] = {0, };
        for (int i = 1; i <= n; i++) {
            int pos = i;
            for (int j = 1; j <= h; j++) {
                if (ladder[pos][j]) pos++;
                else if (pos > 1 && ladder[pos - 1][j]) pos--;
            }
            temp[pos] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (result[i] != temp[i]) return;
        }

        min_Result = min(min_Result, count);
    }
    else {
        flag[idx] = true;
        make_choice(idx + 1, count + 1);

        flag[idx] = false;
        make_choice(idx + 1, count);
    }
}



int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        h = max(h, b[i]);
    }

    init();
    
    make_choice(0, 0);

    cout << min_Result << '\n';

    return 0;
}
