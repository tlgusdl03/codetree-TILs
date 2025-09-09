#include <iostream>

using namespace std;

int N;
int A[100], B[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        bool timeCount[1001] = {false, };
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = A[j]; k < B[j]; k++) {
                timeCount[k] = true;
            }
        }

        int temp = 0;
        for (int j = 1; j < 1001; j++) {
            if(timeCount[j]) temp++;
        }
        result = max(result, temp);
    }

    cout << result;

    return 0;
}