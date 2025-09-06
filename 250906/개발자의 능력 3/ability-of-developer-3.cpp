#include <iostream>

using namespace std;

int abilities[6];

int main() {
    int total = 0;
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
        total += abilities[i];
    }

    int result = 1000000 * 6 + 1;
    for (int i = 0; i < 6 - 2; i++) {
        for (int j = i + 1; j < 6 - 1; j++) {
            for (int k = j + 1; k < 6; k++) {
                int teamA = abilities[i] + abilities[j] + abilities[k];
                int teamB = total - teamA;
                result = min(result, abs(teamA - teamB));
            }
        }
    }

    cout << result;

    return 0;
}