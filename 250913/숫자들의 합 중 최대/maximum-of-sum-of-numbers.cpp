#include <iostream>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    int result = 0;
    for (int i = X; i <= Y; i++) {
        int sum = 0;
        int num = i;

        while (num != 0) {
            int r = num % 10;
            sum += r;
            num /= 10;
        }

        result = max(result, sum);
    }

    cout << result;

    return 0;
}