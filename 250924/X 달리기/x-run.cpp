#include <iostream>

using namespace std;

int X;

int getResult() {
    int time = 0;
    int speed = 1;
    int distance = 0;
    int remain_distance = X;

    while (true) {
        time++;
        distance += speed;
        remain_distance = X - distance;

        if (distance >= X) break;

        if ((speed + distance) < remain_distance) speed++;
        else if (speed > 1) speed--;
    }

    return time;
}

int main() {
    cin >> X;

    int result = getResult();

    cout << result;

    return 0;
}