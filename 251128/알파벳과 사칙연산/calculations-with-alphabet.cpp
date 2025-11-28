#include <iostream>
#include <climits>
using namespace std;

string expression;

int input_Arr[200] = {0, };
int result = INT_MIN;

void solve(int idx) {
    if (idx == expression.length()) {
        int a = input_Arr[0];
        char oper;
        int b = 0;

        for (int i = 1; i < expression.length(); i++) {
            if ('a' <= expression[i] && expression[i] <= 'f') {
                b = input_Arr[i];
                if (oper == '+') {
                    a += b;
                }
                else if (oper == '-') {
                    a -= b;
                }
                else if (oper == '*') {
                    a *= b;
                }
            }
            else {
                oper = expression[i];
            }
        }
        result = max(result, a);
    }
    else {
        if ('a' <= expression[idx] && expression[idx] <= 'f') {
            for (int i = 1; i <= 4; i++) {
                input_Arr[idx] = i;
                solve(idx + 1);
            }
            input_Arr[idx] = 0;
        }
        else {
            solve(idx + 1);
        }    
    }
}

int main() {
    cin >> expression;

    solve(0);

    cout << result << '\n';

    return 0;
}
