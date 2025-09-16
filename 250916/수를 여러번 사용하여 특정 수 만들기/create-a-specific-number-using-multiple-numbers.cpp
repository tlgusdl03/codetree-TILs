#include <iostream>

using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    int result = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int temp = A * i + B * j;
            if (temp <= C) {
                result = max(result, temp);
            }
        }
    }

    cout << result;

    return 0;
}