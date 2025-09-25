#include <iostream>

using namespace std;

int a[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> a[i];

    int diffA = abs(a[0] - a[1]);
    int diffB = abs(a[1] - a[2]);

    int result = 0;

    if (diffA == 1 && diffB == 1) {
        result = 0;
    }
    else if (diffA == 2 && diffB == 2 || diffA == 1 && diffB == 2 || diffA == 2 && diffB == 1) {
        result = 1;
    }
    else if (max(diffA , diffB) > 2) {
        result = max(diffA, diffB) - 1;
    }

    cout << result;

    return 0;
}