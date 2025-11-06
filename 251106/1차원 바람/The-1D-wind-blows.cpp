#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

// 0 - based index
bool isthereSameNum (int r1, int r2) {
    for (int i = 0; i < m; i++) {
        if (a[r1][i] == a[r2][i]) return true;
    }

    return false;
}

// 1 - based index
void wjsvk(int r, char d, bool* visited) {
    // 0 - base로 변환
    int row = r - 1;
    int temp;

    if (visited[row]) return;
    visited[row] = true;

    if (d == 'R') {
        temp = a[row][0];

        for (int i = 0; i < m - 1; i++) {
            a[row][i] = a[row][i + 1];
        }

        a[row][m - 1] = temp;
    }
    else if (d == 'L') {
        temp = a[row][m - 1];

        for (int i = m - 1; i > 0; i--) {
            a[row][i] = a[row][i - 1];
        }

        a[row][0] = temp;
     }

     

     if (row - 1 >= 0 && isthereSameNum(row - 1, row)) {
        if (d == 'L') {
            wjsvk(r - 1, 'R', visited);
        }
        else {
            wjsvk(r - 1, 'L', visited);
        }
     }

     if (row + 1 < n && isthereSameNum(row + 1, row)) {
        if (d == 'L') {
            wjsvk(r + 1, 'R', visited);
        }
        else {
            wjsvk(r + 1, 'L', visited);
        }
     }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        bool visited[100] = {false, };
        wjsvk(r, d, visited);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
