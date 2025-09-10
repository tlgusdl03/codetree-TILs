#include <iostream>

using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int result = - 1;

    for (int i = 0; i <= 1000; i++) {
        int lastIdx = -1;
        for (int j = 0; j < N; j++) {
            if (i == num[j]) {
                if (lastIdx != -1 && (j - lastIdx) <= K){
                    result = max(result, i);
                }
                lastIdx = j;
            }
        }
    }

    cout << result;

    return 0;
}