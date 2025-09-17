#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int N;
string str;

int main() {
    cin >> N;
    cin >> str;

    int result = N + 1;

    // 부분문자열의 길이
    for (int i = 1; i <= N; i++) {
        unordered_map<string, int> freq;
        // 부분문자열의 시작점
        for (int j = 0; j <= N - i; j++) {
            // 부분문자열 추출
            string temp = str.substr(j, i);
            freq[temp]++;
        }

        bool pass = true;
        for (auto &p : freq) {
            if (p.second != 1) {
                pass = false;
                break;
            }
        }

        if (pass) {
            result = i;
            break;
        };
    }

    cout << result;

    return 0;
}