#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
int copyArr[100][100];

void rotate(int r1, int c1, int r2, int c2) {
    int temp1 = a[r1][c2];
    int temp2 = a[r2][c2];
    int temp3 = a[r2][c1];
    int temp4 = a[r1][c1];

    for (int i = c2; i > c1; i--) {
        a[r1][i] = a[r1][i - 1];
    }

    for (int i = r2; i > r1; i--) {
        a[i][c2] = a[i - 1][c2];
    }

    for (int i = c1; i < c2; i++) {
        a[r2][i] = a[r2][i + 1];
    }

    for (int i = r1; i < r2; i++) {
        a[i][c1] = a[i + 1][c1];
    }

    a[r1 + 1][c2] = temp1;
    a[r2][c2 - 1] = temp2;
    a[r2 - 1][c1] = temp3;
    a[r1][c1 + 1] = temp4;
}

void findAvg(int r1, int c1, int r2, int c2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyArr[i][j] = a[i][j];
        }
    }

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            int sum = copyArr[i][j];
            int count = 1;

            if (i - 1 >= 0) {
                sum += copyArr[i - 1][j];
                count++;
            }

            if (i + 1 < n) {
                sum += copyArr[i + 1][j];
                count++;
            }

            if (j - 1 >= 0) {
                sum += copyArr[i][j - 1];
                count++;
            }

            if (j + 1 < m) {
                sum += copyArr[i][j + 1];
                count++;
            }

            int avg = sum / count;
            a[i][j] = avg;
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];


    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int row1 = r1 - 1;
        int col1 = c1 - 1;
        int row2 = r2 - 1;
        int col2 = c2 - 1;

        rotate(row1, col1, row2, col2);
        findAvg(row1, col1, row2, col2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
