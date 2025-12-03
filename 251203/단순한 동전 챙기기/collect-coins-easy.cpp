#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct Coin {
	int num;
	int row;
	int col;
};

int N;
char grid[20][20];
int result = INT_MAX;
vector<Coin> coins;

void solve(int idx, int cnt, int move, int num, int row, int col, int end_Row, int end_Col) {
	if (cnt >= 3) {
		move += abs(end_Row - row) + abs(end_Col - col);
		result = min(result, move);
		return;
	}

	if (idx >= coins.size()) {
		return;
	}

	int next_Row = coins[idx].row;
	int next_Col = coins[idx].col;
	int next_Num = coins[idx].num;

	if (num < next_Num) {
		int d = abs(next_Row - row) + abs(next_Col - col);
		solve(idx + 1, cnt + 1, move + d, next_Num, next_Row, next_Col, end_Row, end_Col);
	}

	solve(idx + 1, cnt, move, num, row, col, end_Row, end_Col);

	return;
}

int main() {
	cin >> N;

	int start_Row = 0;
	int start_Col = 0;
	int end_Row = 0;
	int end_Col = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if ('1' <= grid[i][j] && grid[i][j] <= '9') {
				coins.push_back({ grid[i][j] - '0', i, j });
			}

			if (grid[i][j] == 'S') {
				start_Row = i;
				start_Col = j;
			}

			if (grid[i][j] == 'E') {
				end_Row = i;
				end_Col = j;
			}
		}
	}

	sort(coins.begin(), coins.end(), [](const Coin& a, Coin& b) {
		return a.num < b.num;
	});

	solve(0, 0, 0, 0, start_Row, start_Col, end_Row, end_Col);

	if (result == INT_MAX) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n';
	}

	return 0;
}
