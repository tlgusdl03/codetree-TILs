#include <iostream>
#include <deque>
using namespace std;

int N, M, K;
int location[101][101] = {0, };
char d[1000];
int p[1000];
deque<pair<int, int>> snake;

bool isInRange(int x, int y) {
    return (0 < x && x <= N && 0 < y && y <= N);
}

int move() {
    int count = 0;

    location[1][1] = 2;
    snake.push_front({1, 1});

    for (int i = 0; i < K; i++) {
        char direction = d[i];
        int distance = p[i];

        pair<int, int> head = snake.front();

        int cur_X = head.first;
        int cur_Y = head.second;

        for (int j = 0; j < distance; j++) {
            if (direction == 'U') {
                cur_X--;
            }
            else if (direction == 'D') {
                cur_X++;
            }
            else if (direction == 'R') {
                cur_Y++;
            }
            else if (direction == 'L') {
                cur_Y--;
            }

            count++;

            if (!isInRange(cur_X, cur_Y) || location[cur_X][cur_Y] == 2) return count;

            if (location[cur_X][cur_Y] != 1) {
                pair<int, int> tail = snake.back();
                location[tail.first][tail.second] = 0;
                snake.pop_back();
            }
            
            location[cur_X][cur_Y] = 2;
            snake.push_front({cur_X, cur_Y});
        }
    }

    return count;
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        location[x][y] = 1;
    }

    for (int i = 0; i < K; i++) cin >> d[i] >> p[i];

    int result = move();

    cout << result;

    return 0;
}
