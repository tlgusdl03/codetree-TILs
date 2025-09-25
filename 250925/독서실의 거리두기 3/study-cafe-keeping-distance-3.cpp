#include <iostream>
#include <string>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    int longestStartIdx = 0;
    int longestEndIdx = 0;
    int longest = 0;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        if (seats[i] == '0') {
            temp++;
        }
        else if (seats[i] == '1') {
            if (temp > longest) {
                longest = temp;
                longestStartIdx = i - longest;
                longestEndIdx = i - 1;
            }
            temp = 0;
        }
    }

    seats[(longestStartIdx + longestEndIdx) / 2] = '1';

    int result = N + 1;
    int lastIdx = -1;
    for (int i = 0; i < N; i++) {
        if (seats[i] == '1') {
            if (lastIdx != -1) {
                result = min(result, i - lastIdx);
            }
            lastIdx = i;
        }
    }
    
    cout << result;

    return 0;
}