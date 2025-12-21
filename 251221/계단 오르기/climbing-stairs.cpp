#include <iostream>

using namespace std;

int tb[1001];
int n;

int main() {
    cin >> n;

    tb[0] = 0;
    tb[1] = 0;
    tb[2] = 1;
    tb[3] = 1;

    for (int i = 4; i < 1000; i++) {
        tb[i] = (tb[i - 2] + tb[i - 3]) % 10007;
    }

    cout << tb[n] << '\n';

    return 0;
}