#include <iostream>

using namespace std;

int N;
int x1[100], x2[100];

bool getResult (int a1, int a2, int b1, int b2) {
    return (a1 < b1 && a2 > b2) || (a1 > b1 && a2 < b2);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> x2[i];
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        bool isDuplicated = false;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if(getResult(x1[i], x2[i], x1[j], x2[j])){
                isDuplicated = true;
                break;
            }
        }
        if (!isDuplicated) result++;
    }

    cout << result;

    return 0;
}