#include <iostream>
using namespace std;

int main() {
    int a, b, res1, res2;

    cin >> a >> b;

    if (a < b) {
        res1 = 1;
    }
    else {
        res1 = 0;
    }

    if (a == b) {
        res2 = 1;
    }
    else {
        res2 = 0;
    }

    cout << res1 << " " << res2;
    return 0;
}