#include <iostream>
#include <string>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    int longest = 0;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        if (seats[i] == '0') {
            temp++;
        }
        else if (seats[i] == '1') {
            longest = max(longest, temp);
            temp = 0;
        }
    }

    cout << longest / 2 + 1;

    return 0;
}