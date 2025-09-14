#include <iostream>
#include <string>
using namespace std;

int X, Y;

bool findPelindrome(int num) {
    string s = to_string(num);
    int len = s.length();

    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }

    return true;
}

int main() {
    cin >> X >> Y;

    int result = 0;

    for (int i = X; i <= Y; i++) {
        if(findPelindrome(i)) result++;
    }

    cout << result;
    return 0;
}