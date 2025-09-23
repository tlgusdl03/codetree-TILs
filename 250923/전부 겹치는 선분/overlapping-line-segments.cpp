#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = x1[i], b = x2[i];
            int c = x1[j], d = x2[j];

            if (b < c || d < a) continue;

            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}