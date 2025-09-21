#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);

    int result = 0;
    for (int i = 0; i <= 1000000; i++) {
        int lastIdx = -1;
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (num[j] == i) {
                if (lastIdx != -1) {
                    if (j - lastIdx <= K) {
                        temp++;
                    }
                }
                lastIdx = j;
            }
        }
        result = max(result, temp);
    }

    cout << result;

    return 0;
}