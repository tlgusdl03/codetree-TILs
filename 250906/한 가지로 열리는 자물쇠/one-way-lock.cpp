#include <iostream>

using namespace std;

int N;
int a, b, c;

int main() {
    cin >> N;
    cin >> a >> b >> c;

    int result = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                int distanceA = abs(a - i);
                int distanceB = abs(b - j);
                int distanceC = abs(c - k);

                if (distanceA <= 2 || distanceB <= 2 || distanceC <= 2) result++;
            }
        }
    }

    cout << result;

    return 0;
}