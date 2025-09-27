#include <iostream>

using namespace std;

int n;
int a[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int first = 101;

    for (int i = 1; i <= n; i++) {
        first = min(first, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == first) {
            a[i] = 1000001;
        }
    }

    int second = 101;
    for (int i = 1; i <= n; i++) {
        second = min(second, a[i]);
    }

    int idx = -1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == second) {
            idx = i;
            count++;
        }
    }

    if (count == 0 || count > 1) {
        cout << "-1";
    }
    else {
        cout << idx;
    }

    return 0;
}