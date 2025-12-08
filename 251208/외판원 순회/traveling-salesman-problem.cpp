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

bool canGo(int i, int j) {
    return (!visited[j] && !A[i][j]);
}

void findAnswer(int prev_Row) {

    if (A[prev_Row][0] == 0) return;

    int result = 0;

    for (int i = 0; i < cost.size(); i++) {
        result += cost[i];
    }

    result += A[prev_Row][0];

    answer = min(answer, result);
}

void solve(int prev_Row, int cnt) {
    if (cnt == n) {
        findAnswer(prev_Row);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (A[prev_Row][i] == 0) continue;

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
    solve(0, 1); 
    
    cout << answer << '\n';

    return 0;
}
