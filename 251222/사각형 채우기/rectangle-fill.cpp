#include <iostream>

using namespace std;

int n;
int tb[1001];

int main() {
    cin >> n;

    tb[0] = 0;
    tb[1] = 1;
    tb[2] = 2;

    for (int i = 3; i < 1001; i++) {
        tb[i] = (tb[i - 1] + tb[i - 2]) % 10007;
    }

    cout << tb[n] << '\n';

    return 0;
}
