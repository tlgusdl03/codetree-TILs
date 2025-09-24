#include <iostream>

using namespace std;

int X;

int getResult() {
    int time = 0;
    int speed = 0;
    int distance = 0;

    while (distance < X) {
        int remain_X = X - distance;

        if (remain_X >= ((speed + 1) * (speed + 2)) / 2) speed++;
        else if (remain_X < (speed * (speed + 1)) / 2) speed--;

        distance += speed;

        time++;
    }
    
    return time;
}


int main() {
    cin >> X;

    int result = getResult();

    cout << result;

    return 0;
}