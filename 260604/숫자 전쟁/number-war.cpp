#include <iostream>
#include <cmath>
using namespace std;

int n;
int first_cards[1000];
int second_cards[1000];
int dp[1000][1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> second_cards[i];
    }

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) continue;

            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);

            if (first_cards[i] > second_cards[j]) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + second_cards[j]);
            }
            else if (first_cards[i] < second_cards[j]) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
    }
    
    int answer = 0;

    for (int i = 0; i <= n; i++) {
        answer = max(answer, dp[i][n]);
    }

    for (int j = 0; j <= n; j++) {
        answer = max(answer, dp[n][j]);
    }

    cout << answer;

    return 0;
}

