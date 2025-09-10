#include <iostream>

using namespace std;

int N;
int x1[100], x2[100];

bool getResult (int x1, int x2, int y1, int y2) {
    return ((x1 < y1 && x2 > y2) || (x1 > y1 && x2 < y2));
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> x2[i];
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if(getResult(x1[i], x2[i], x1[j], x2[j])) result++;
        }
    }

    cout << result;

    return 0;
}