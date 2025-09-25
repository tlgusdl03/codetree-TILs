#include <iostream>
#include <algorithm>
using namespace std;

int pos[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> pos[i];

    sort(pos, pos + 3);

    int result = 0;

    int betA = abs(pos[0] - pos[1]);
    int betB = abs(pos[1] - pos[2]);

    if (betA == 1 && betB == 1) {
        result = 0;
    }
    else if (betA == 2 || betB == 2) {
        result = 1;
    }
    else {
        result = 2;
    }

    cout << result;

    return 0;
}
