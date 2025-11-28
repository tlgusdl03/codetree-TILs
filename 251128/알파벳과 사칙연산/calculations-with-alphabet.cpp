#include <iostream>
#include <climits>
using namespace std;

string expression;

int input_Arr[6] = {0, };
int result = INT_MIN;

int calc() {
    int n = expression.length();
    int value = input_Arr[expression[0] - 'a'];
    char oper = 0;

    for (int i = 1; i < n; i++) {
        char ch = expression[i];

        if ('a' <= ch && ch <= 'f') {
            int idx = ch - 'a';
            int v = input_Arr[idx];
            if (oper == '+') value += v;
            else if (oper == '-') value -= v;
            else if (oper == '*') value *= v;
        }
        else {
            oper = ch;
        }
    }

    return value;
}

void solve(int idx) {
    if (idx == 6) {
        int a = calc();
        result = max(result, a);
    }
    else {
        for (int i = 1; i <= 4; i++) {
            input_Arr[idx] = i;
            solve(idx + 1);
            input_Arr[idx] = 0;
        } 
    }  
}

int main() {
    cin >> expression;

    solve(0);

    cout << result << '\n';

    return 0;
}
