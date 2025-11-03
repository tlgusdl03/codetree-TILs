#include <iostream>

using namespace std;

int n;
int grid[20][20];

bool isInRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int findSum(int x, int y) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        int rightX = x - i; int rightY = y + i;
        for (int j = 1; j <= n; j++) {
            int leftX = x - j; int leftY = y - j;
            int topX = x - i - j; int topY = y + i - j;

            int temp = 0;

            if (!isInRange(rightX, rightY, n) 
            || !isInRange(leftX, leftY, n) 
            || !isInRange(topX, topY, n)) continue;

            int curX = x; int curY = y;

            while (curY < rightY) {
                temp += grid[curX][curY];
                curX--;
                curY++;
            }

            while (curY > topY) {
                temp += grid[curX][curY];
                curX--;
                curY--;
            }

            while (curY > leftY) {
                temp += grid[curX][curY];
                curX++;
                curY--;
            }

            while (curY < y) {
                temp += grid[curX][curY];
                curX++;
                curY++;
            }

            result = max(result, temp);
        }
    }
    return result;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 아래 꼭짓점 = 1, 오른쪽 꼭짓점 = 2, 위 꼭짓점 = 3, 왼쪽 꼭짓점 = 4
    // 2차원 배열을 순회 하며 1번을 결정함, 각 1번 마다 2번과 4번에 대해 완전 탐색 실시, 3번은 2번과 4번에 따라 결정됨
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, findSum(i, j));
        }
    }

    cout << result;

    return 0;
}
