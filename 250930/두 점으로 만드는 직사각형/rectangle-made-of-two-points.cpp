#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    int minX, minY, maxX, maxY;

    minX = min(x1, a1);
    minY = min(y1, b1);

    maxX = max(x2, a2);
    maxY = max(y2, b2);

    cout << (maxX - minX) * (maxY - minY) << '\n';

    return 0;
}