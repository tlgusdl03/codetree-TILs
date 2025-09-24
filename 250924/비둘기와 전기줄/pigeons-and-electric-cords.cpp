#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> pigeons_position[11]; 

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int pigeon, position;
        cin >> pigeon >> position;
        pigeons_position[pigeon].push_back(position);
    }

    int result = 0;
    for (int i = 1; i <= 10; i++) { // pigeon 번호가 1~10
        if (pigeons_position[i].empty()) continue;
        int last = pigeons_position[i][0]; // 첫 번째 위치
        for (auto &j : pigeons_position[i]) {
            if (last != j) {
                result++;
            }
            last = j;
        }
    }

    cout << result;

    return 0;
}
