#include <iostream>

using namespace std;

int n;
int l[10], r[10];

bool getResult(int a, int b, int c) {
    int arr[101] = {0 ,};
    for (int i = 0; i < n; i++) {
        if (i == a || i == b || i == c) continue;
        int left = l[i];
        int right = r[i];
        for (int j = left; j <= right; j++) {
            arr[j]++;
        }
    }

    for (int i = 0; i <= 100; i++) {
        if (arr[i] > 1) return false;
    }

    return true;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    int result = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                if (getResult(i, j, k)) result++;
            }
        }
    }

    cout << result;

    return 0;
}