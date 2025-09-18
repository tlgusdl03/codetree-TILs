#include <iostream>

using namespace std;

int n;
int a[10], b[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int result = -1;
    for (int i = 1; i <= 5000; i++) {
        int num = i;
        bool pass = true;
        for (int j = 0; j < n; j++) {
            num *= 2;
            if (!(a[j] <= num && num <= b[j])) {
                pass = false;
                break;
            }
        }
        if (pass) {
            result = i;
            break;
        }
    }

    cout << result;

    return 0;
}