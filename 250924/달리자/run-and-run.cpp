#include <iostream>

using namespace std;

int n;
int A[100];
int B[100];

int main() {
    cin >> n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }


    for (int i = 0; i < n; i++) {
        if (A[i] > B[i]) {
            int diff = A[i] - B[i];
            if (i != n - 1) A[i + 1] += diff;
            result += diff;
        }
    }

    cout << result;

    return 0;
}