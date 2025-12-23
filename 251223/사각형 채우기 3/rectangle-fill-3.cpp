#include <iostream>
#define MAX_N 1000
#define MOD 1000000007
using namespace std;

int n;
int tb[MAX_N + 1];
int main() {
    cin >> n;

    tb[0] = 1;
    tb[1] = 2;
    tb[2] = 7;

    for (int i = 3; i < MAX_N + 1; i++) {
        tb[i] = (tb[i - 3] * 2 + tb[i - 2] * 3 + tb[i - 1] * 2) % MOD;
    }

    cout << tb[n];

    return 0;
}
