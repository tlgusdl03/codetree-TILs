#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];

int main() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    int result = 5 * 1000 + 1;
    bool cannot = true;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = k + 1; l < 5; l++) {
                    if (i == k || j == l || i == l || j == k) continue;

                    int teamA = arr[i] + arr[j];
                    int teamB = arr[k] + arr[l];
                    int teamC = total - teamA - teamB;

                    if (teamA == teamB || teamB == teamC || teamA == teamC) continue;

                    int maxTeam = max({teamA, teamB, teamC});
                    int minTeam = min({teamA, teamB, teamC});

                    result = min(result, abs(maxTeam - minTeam));
                    cannot = false;
                }
            }
        }
    }

    if (cannot) {
        cout << -1 << '\n';
    }
    else {
        cout << result << '\n';
    }

    return 0;
}