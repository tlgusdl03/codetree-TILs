#include <iostream>

using namespace std;

int N, M;
int A[100], B[100];
int num[100] = {0,};

int main() {
    cin >> N >> M;

    if (N < M) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = 0; i < M; i++){
        num[B[i]]++;
    }

    int result = 0;

    for (int i = 0; i < N - M + 1; i++){
        int temp[100];
        for (int j = 0; j < 100; j++){
            temp[j] = 0;
        }

        for (int j = i; j < i + M; j++){
            temp[A[j]]++;
        }

        bool pass = true;

        for (int j = 0; j < 100; j++){          
            if (temp[j] != num[j]) {
                pass = false;
                break;
            }
        }

        if (pass) result++;
    }

    cout << result;
    return 0;
}