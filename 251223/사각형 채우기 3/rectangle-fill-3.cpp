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
        int temp = 0;
        for (int j = 0; j <= i - 3; j++) {
            temp += tb[j] * 2 % MOD;
        }
        tb[i] = (temp + tb[i - 2]* 3 % MOD + tb[i - 1] * 2 % MOD) % MOD;
    }

    cout << tb[n];

    return 0;
}
