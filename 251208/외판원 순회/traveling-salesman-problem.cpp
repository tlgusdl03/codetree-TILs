#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int A[10][10];
bool visited[10];
vector<int> cost;
int answer = INT_MAX;

void findAnswer(int prev_Row) {
    int result = 0;

    cost.push_back(A[prev_Row][0]);

    for (int i = 0; i < cost.size(); i++) {
        result += cost[i];
    }

    answer = min(answer, result);

    cost.pop_back();
}

void solve(int prev_Row, int cnt) {
    if (cnt == n) {
        findAnswer(prev_Row);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        cost.push_back(A[prev_Row][i]);
        solve(i, cnt + 1);

        visited[i] = false;
        cost.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    visited[0] = true;
    cost.push_back(A[0][0]);
    solve(0, 1); 
    
    cout << answer << '\n';

    return 0;
}
