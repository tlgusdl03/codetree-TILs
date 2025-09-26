#include <iostream>
#include <string>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    int result = 0;

    for (int i = 0; i < N; i++) {
        // i : 새로 추가할 자리
        if (seats[i] == '1') continue;

        string copySeats = seats;
        copySeats[i] = '1';

        int temp = N + 1;
        int lastIdx = -1;

        for (int j = 0; j < N; j++) {
            if (copySeats[j] == '1') {
                if (lastIdx != -1) {
                    temp = min(temp, j - lastIdx);
                }
                lastIdx = j;
            }
        }

        result = max(result, temp);

    }

    cout << result;
    
    return 0;
}