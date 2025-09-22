#include <iostream>
#include <cmath>
using namespace std;

int N;
int heights[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    int result = pow(100, 2) * N + 1;

    for (int i = 0; i <= 100; i++) {
        // i : 가장 낮은 언덕의 높이
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (heights[j] < i) {
                temp += pow(i - heights[j], 2);
            }
            else if (heights[j] - i > 17) {
                temp += pow(heights[j] - (17 + i), 2);
            }
        }
        result = min(result, temp);
    }

    cout << result;

    return 0;
}