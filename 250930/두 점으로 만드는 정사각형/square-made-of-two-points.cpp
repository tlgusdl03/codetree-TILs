#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    int minX = min(x1, a1);
    int minY = min(y1, b1);

    int maxX = max(x2, a2);
    int maxY = max(y2, b2);

    int len = max(maxX - minX, maxY - minY);

    cout << len * len << '\n';

    return 0;
}