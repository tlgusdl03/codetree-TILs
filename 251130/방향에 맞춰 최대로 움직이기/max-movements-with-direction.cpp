#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[5][5];
int move_dir[5][5];
int r, c;

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int result = 0;

bool isInRange(int row, int col) {
    return (0 < row && row <= n && 0 < col && col <= n);
}

void solve(int count, int row, int col) {

    result = max(result, count);

    if (count == n * n - 1) return;

    int cur_Row = row;
    int cur_Col = col;
    int cur_num = num[row][col];
    int direction = move_dir[row][col];

    while(true) {
        int next_Row = cur_Row + dx[direction];
        int next_Col = cur_Col + dy[direction];

        if (!isInRange(next_Row, next_Col)) return;

        if (cur_num < num[next_Row][next_Col]) {
            solve(count + 1, next_Row, next_Col);
        }

        cur_Row = next_Row;
        cur_Col = next_Col;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> num[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    solve(0, r, c);

    cout << result << '\n';

    return 0;
}
