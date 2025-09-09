#include <iostream>

using namespace std;

int N;
int x[100];
int y[100];

int getArea(int i, int j, int k) {

    int xDistance = 0;
    int yDistance = 0;

    if (y[i] == y[j]) {
        xDistance = abs(x[j] - x[i]);
    }
    else if (y[j] == y[k]) {
        xDistance = abs(x[j] - x[k]);
    }
    else if (y[i] == y[k]) {
        xDistance = abs(x[i] - x[k]);
    }

    if (x[i] == x[j]) {
        yDistance = abs(y[i] - y[j]);
    }
    else if (x[j] == x[k]) {
        yDistance = abs(y[j] - y[k]);
    }
    else if (x[i] == x[k]) {
        yDistance = abs(y[i] - y[k]);
    }

    return xDistance * yDistance;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int result = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                result = max(result, getArea(i, j, k));
            }
        }
    }

    cout << result;
    
    return 0;
}