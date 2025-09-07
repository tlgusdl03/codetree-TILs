#include <iostream>

using namespace std;

int n;
int a[10], b[10], c[10];

bool isTrue(int i, int j, int k) {

    for (int idx = 0; idx < n; idx++) {
        int num_100 = a[idx] / 100;
        int num_10 = a[idx] / 10 % 10;
        int num_1 = a[idx] % 10;

        int cnt1 = 0;
        int cnt2 = 0;

        if (i == num_100) cnt1++;
        if (j == num_10) cnt1++;
        if (k == num_1) cnt1++;

        if (i == num_10 || i == num_1) cnt2++;
        if (j == num_100 || j == num_1) cnt2++;
        if (k == num_100 || k == num_10) cnt2++;

        if (cnt1 != b[idx] || cnt2 != c[idx]) return false;
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    int result = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                if (i == j || j == k || i == k) continue;
                if (isTrue(i, j , k)) result++;
            }
        }
    }

    cout << result;

    return 0;
}