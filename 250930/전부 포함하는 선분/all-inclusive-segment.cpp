#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    int result = 101;
    for (int i = 0; i < n; i++) {
        int minX = 101, maxX = 0;
        for (int j = 0; j < n; j++) {

            if (i == j) continue;

            minX = min(minX, x1[j]);
            maxX = max(maxX, x2[j]);
        }

        result = min(result, maxX - minX);
    }

    cout << result;
    
    return 0;
}