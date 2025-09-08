#include <iostream>
#include <algorithm>
using namespace std;

int ability[6];

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
    }

    int result = 1000000 * 6 + 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                for (int l = 0; l < 6; l++) {
                    for (int m = 0; m < 6; m++) {
                        for (int n = 0; n < 6; n++) {
                            if (i == j || i == k || i == l || i == m || i == n 
                            || j == k || j == l || j == m || j == n
                            || k == l || k == m || k == n 
                            || l == m || l == n
                            || m == n) continue;

                            int highestTeam = max({ability[i] + ability[j], ability[k] + ability[l], ability[m] + ability[n]});
                            int lowestTeam = min({ability[i] + ability[j], ability[k] + ability[l], ability[m] + ability[n]});

                            result = min(result, highestTeam - lowestTeam);
                        }
                    }
                }
            }
        }
    }

    cout << result;

    return 0;
}