#include <iostream>
using namespace std;

int K, N;
int btr[8];

void backTracking(int k, int n) {
    // 숫자를 하나 고르는 행위를 N번 반복하였다면
    if (n == N) {
        // 뽑았던 수를 출력하고 더 이상 진행하지 않음
        for (int i = 0; i < n; i++) {
            cout << btr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    // 그렇지 않다면
    // 1이상 K이하의 수를 하나 고른 후 다음 단계로 진행
    for (int i = 1; i <= K; i++) {
        btr[n] = i;
        backTracking(i, n + 1);
    }
}

int main() {
    cin >> K >> N;
    
    backTracking(1, 0);

    return 0;
}