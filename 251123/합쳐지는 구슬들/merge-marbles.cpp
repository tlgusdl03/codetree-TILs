#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t;
int r[2500], c[2500];
char d[2500];
int w[2500];
bool able[2500];

bool isInRange(int row, int col) {
    return (0 < row && row <= n && 0 < col && col <= n);
}

void merge(vector<int> &arr) {
    int biggest_Idx = 0;
    int total_Weight = 0;

    if (arr.size() <= 1) return;

    for (int i = 0; i < arr.size(); i++) {
        biggest_Idx = max(biggest_Idx, arr[i]);
        total_Weight += w[arr[i]];
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == biggest_Idx) {
            w[arr[i]] = total_Weight;
        }
        else {
            able[arr[i]] = false;
        }
    }
}

void changeDirection(int i) {
    if (d[i] == 'U') {
        d[i] = 'D';
    }
    else if (d[i] == 'D') {
        d[i] = 'U';
    }
    else if (d[i] == 'L') {
        d[i] = 'R';
    }
    else if (d[i] == 'R') {
        d[i] = 'L';
    }
}

void move(int i) {
    int next_Row = r[i];
    int next_Col = c[i];

    if (d[i] == 'U') {
        next_Row--;
    }
    else if (d[i] == 'D') {
        next_Row++;
    }
    else if (d[i] == 'L') {
        next_Col--;
    }
    else if (d[i] == 'R') {
        next_Col++;
    }

    if (isInRange(next_Row, next_Col)) {
        r[i] = next_Row;
        c[i] = next_Col;
    }
    else {
        changeDirection(i);
    }
}

void solve() {

    for (int time = 0; time < t; time++) {
        vector<int> temp[51][51];
        for (int i = 0; i < m; i++) {
            if (!able[i]) continue;

            move(i);

            temp[r[i]][c[i]].push_back(i);
        }

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n; col++) {
                merge(temp[row][col]);
            }
        }
    }

    int marble_Count = 0;
    int heaviest = 0;

    for (int i = 0; i < m; i++) {
        if (able[i]) {
            marble_Count++;
            heaviest = max(heaviest, w[i]);
        }
    }

    cout << marble_Count << " " << heaviest << '\n';

    return;
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> d[i] >> w[i];
        able[i] = true;
    }

    solve();

    return 0;
}
