#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int grid[200][200];

pair<int, int> shapes[6][3] = {
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {1, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {0, 1}, {0, 2} },
    { {0, 0}, {1, 0}, {2, 0} }
};

bool isInRange (int x, int y, int n, int m) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int findSum(int x, int y) {
    int result = 0;

    for (int i = 0; i < 6; i++) {
        int temp = 0;

        for (int j = 0; j < 3; j++) {
            int nx = x + shapes[i][j].first;
            int ny = y + shapes[i][j].second;

            if (!isInRange(nx, ny, n, m)) continue;

            temp += grid[nx][ny];
        }

        result = max(result, temp);
    }

    return result;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result = max(result, findSum(i, j));
        }
    }

    cout << result;

    return 0;
}
