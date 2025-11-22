#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Marble {
public:
	int num;
	int row;
	int col;
	char direction;
	int speed;
	bool able;

	Marble(int num, int row, int col, char direction, int speed) {
		this->num = num;
		this->row = row;
		this->col = col;
		this->direction = direction;
		this->speed = speed;
		this->able = true;
	}

	void changeDirection() {
		if (this->direction == 'U') {
			this->direction = 'D';
		}
		else if (this->direction == 'D') {
			this->direction = 'U';
		}
		else if (this->direction == 'L') {
			this->direction = 'R';
		}
		else if (this->direction == 'R') {
			this->direction = 'L';
		}
	}
};

int n, m, t, k;
// 접근 방법 : 구슬의 번호(num), 인덱스
vector<Marble> marbles;

bool isInRange(int row, int col) {
	return (0 < row && row <= n && 0 < col && col <= n);
}

int solve() {
	for (int time = 0; time < t; time++) {
		vector<int> temp[51][51];
		for (int num = 0; num < m; num++) {
			if (!marbles[num].able) continue;

			int next_Row = marbles[num].row;
			int next_Col = marbles[num].col;

			for (int move = 0; move < marbles[num].speed; move++) {
				if (marbles[num].direction == 'U') {
					next_Row--;
				}
				else if (marbles[num].direction == 'D') {
					next_Row++;
				}
				else if (marbles[num].direction == 'L') {
					next_Col--;
				}
				else if (marbles[num].direction == 'R') {
					next_Col++;
				}

				if (!isInRange(next_Row, next_Col)) {
					marbles[num].changeDirection();
					
					if (marbles[num].direction == 'U') {
					next_Row--;
					}
					else if (marbles[num].direction == 'D') {
						next_Row++;
					}
					else if (marbles[num].direction == 'L') {
						next_Col--;
					}
					else if (marbles[num].direction == 'R') {
						next_Col++;
					}

					move--;
				}
			}

			temp[next_Row][next_Col].push_back(num);
			marbles[num].row = next_Row;
			marbles[num].col = next_Col;
		}

		for (int row = 1; row <= n; row++) {
			for (int col = 1; col <= n; col++) {
				sort(temp[row][col].begin(), temp[row][col].end(),
					[](int a, int b) {
					if (marbles[a].speed != marbles[b].speed)
						return marbles[a].speed > marbles[b].speed;
					return a > b;
				}
				);
			}
		}

		for (int row = 1; row <= n; row++) {
			for (int col = 1; col <= n; col++) {
				if (temp[row][col].size() > k) {
					int count = temp[row][col].size();
					for (int i = k; i < count; i++) {
						int num = temp[row][col].back();
						marbles[num].able = false;
					}
				}
			}
		}
	}

	int result = 0;

	for (int i = 0; i < marbles.size(); i++) {
		if (marbles[i].able) result++;
	}

	return result;
}

int main() {
	cin >> n >> m >> t >> k;

	int r, c, v;
	char d;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> d >> v;
		marbles.push_back({i, r, c, d, v});
	}

	cout << solve();

	return 0;
}
