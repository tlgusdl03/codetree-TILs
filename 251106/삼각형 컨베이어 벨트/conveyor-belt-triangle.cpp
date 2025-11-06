#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < t; i++) {
        int temp1 = d[2];

        int temp2 = l[2];
        for (int j = n - 1; j > 0 ; j--) {
            l[j] = l[j - 1];
        }
        l[0] = temp1;

        int temp3 = r[2];
        for (int j = n - 1; j > 0 ; j--) {
            r[j] = r[j - 1];
        }
        r[0] = temp2;

        for (int j = n - 1; j > 0 ; j--) {
            d[j] = d[j - 1];
        }
        d[0] = temp3;
    }

    for (int i = 0 ; i < n; i++) {
        cout << l[i] << " ";
    }
    cout << '\n';

    for (int i = 0 ; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << '\n';

    for (int i = 0 ; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << '\n';

    return 0;
}
