#include <iostream>
using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int result = 0;
    int resultIdx = 0;
    for (int i = 0; i <= 1000000; i++) {
        int lastIdx = -1;
        int tempSum = 0;
        for (int j = 0; j <= N; j++) {
            if (num[j] == i) {
                if (lastIdx != -1) {
                    if (j - lastIdx <= K) {
                        tempSum++;
                    }
                }
                lastIdx = j;
            }
        }

        if (tempSum != 0) tempSum++;

        if (tempSum != 0 && result <= tempSum) {
            result = tempSum;
            resultIdx = i;
        }
    }

    cout << resultIdx;

    return 0;
}