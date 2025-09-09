#include <iostream>
#include <cmath>
using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int result = pow(1000, 2) * 2 + 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int distance = pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2);
            result = min(result, distance);
        }
    }

    cout << result;

    return 0;
}