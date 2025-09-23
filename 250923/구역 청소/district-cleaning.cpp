#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b;
    cin >> c >> d;

    if (b < c || d < a) {
        cout << (b - a) + (d - c);
    }
    else if (a < c && d < b || c < a && b < d) {
        cout << max((b - a), (d - c));
    }
    else {
        cout << max(b, d) - min(a, c);
    }

    return 0;
}