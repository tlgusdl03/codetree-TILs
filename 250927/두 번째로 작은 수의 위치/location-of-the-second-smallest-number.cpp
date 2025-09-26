#include <iostream>

using namespace std;

int n;
int a[100];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int first = 101;
    int second = 101;
    int idx = 0;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        first = min(first, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (first == a[i]) {
            a[i] = 101;
        }
    }

    for (int i = 1; i <= n; i++) {
        second = min(second, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (second == a[i]) {
            idx = i;
            count++;
        }
    }

    if (count >= 2 || count == 0) {
        cout << -1;
    }
    else {
        cout << idx;
    }

    return 0;
}