#include <iostream>
#include <climits>
#include <cmath>
#define MAX_OPERRAND 6
using namespace std;

// climits 헤더를 사용하여 답을 정수의 최솟값으로 초기화 시킴
int ans = INT_MIN;
// a ~ e까지에 들어갈 수를 고르기 위해 배열을 선언함
int btr[6];
string str;
int N;

// 알파벳에 해당하는 고른 값을 반환함
int trans(char a) {
    return btr[a - 'a'];
}

// 알파벳, 연산자, 알파벳, ... , 연산자, 알파벳의 순서로 들어온 식에 접근하여 계산을 진행함
void calculator() {
    int result = trans(str[0]);
    for (int i = 1; i < N; i += 2) {
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

// a ~ e까지 대입할 수를 고름
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