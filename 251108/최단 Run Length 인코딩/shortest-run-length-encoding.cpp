#include <iostream>
#include <string>

using namespace std;

string A;

int findLen(string A) {
    int len = A.length();
    string result = "";

    char last = A[0];
    int count = 1;
    for (int i = 1; i < len; i++) {
        if (A[i] == last) {
            count++;
        }
        else {
            result += last;
            result += to_string(count);
            last = A[i];
            count = 1;
        }
        
    }

    result += last;
    result += to_string(count);

    return result.length();
}

string rotate(string A) {
    int len = A.length();
    char temp = A[len - 1];

    for (int j = len - 1; j > 0; j--) {
        A[j] = A[j - 1];
    }

    A[0] = temp;

    return A;
}

int findMinLen(string A) {
    int result = 20;
    int len = A.length();


    for (int i = 0; i < len; i++) {
        
        string rotated_A = rotate(A);

        A = rotated_A;

        int tempLen = findLen(rotated_A);

        result = min(result, tempLen);
    }

    return result;
}

int main() {
    cin >> A;

    int result = findMinLen(A);

    cout << result;

    return 0;
}
