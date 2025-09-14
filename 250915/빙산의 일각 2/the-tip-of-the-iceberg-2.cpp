#include <iostream>

using namespace std;

int n;
int h[100];

int main() {
    cin >> n;

    int MIN_H = 1001;
    int MAX_H = 0;

    int result = 0;

    for (int i = 0; i < n; i++) {
        cin >> h[i];

        MIN_H = min(MIN_H, h[i]);
        MAX_H = max(MAX_H, h[i]);

        for (int i = MIN_H; i <= MAX_H; i++) {
            int count = 0;

            bool upper = false;

            for (int j = 0; j < n; j++) {
                if (!upper && h[j] > i) {
                    upper = true;
                    count++;
                }
                else if (upper && h[j] <= i) {
                    upper = false;
                }
            }

            result = max(result, count);
        }
    }

    cout << result;

    return 0;
}