#include <iostream>
#include <algorithm>
using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;

    cout << min({
        abs(b - a),
        abs(a - x) + abs(b - y),
        abs(a - y) + abs(b - x)
    });

    return 0;
}