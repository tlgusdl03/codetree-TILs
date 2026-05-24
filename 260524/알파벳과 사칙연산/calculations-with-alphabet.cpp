#include <iostream>
#include <climits>
#include <cmath>
#define MAX_OPERRAND 6
using namespace std;

int ans = INT_MIN;
int btr[6];
string str;
int N;

int trans(char a) {
    return btr[a - 'a'];
}

void calculator() {
    int result = trans(str[0]);
    for (int i = 1; i < N; i++) {
        if (str[i] == '+') {
            result += trans(str[i + 1]);
        }
        else if (str[i] == '-') {
            result -= trans(str[i + 1]);
        }
        else if (str[i] == '*') {
            result *= trans(str[i + 1]);
        }
    }
    ans = max(ans, result);
}

void backTracking(int cnt) {
    if (cnt == MAX_OPERRAND) {
        calculator();
        return;
    }
    
    for (int i = 1; i <= 4; i++) {
        btr[cnt] = i;
        backTracking(cnt + 1);
    }
}

int main() {
    cin >> str;
    N = str.length();

    backTracking(0);

    cout << ans;

    return 0;
}