#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[9];
vector<int> answer;

void printAnswer() {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << '\n';
}

void solve(int cnt) {
    if (cnt == n) {
        printAnswer();
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (visited[i]) continue;

        answer.push_back(i);
        visited[i] = true;
        solve(cnt + 1);

        answer.pop_back();
        visited[i] = false;
    }
}
int main() {
    cin >> n;

    solve(0);

    return 0;
}
