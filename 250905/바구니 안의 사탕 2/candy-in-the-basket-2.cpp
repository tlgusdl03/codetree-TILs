#include <iostream>

using namespace std;

int N, K;

// candy, pos는 N개의 길이를 가지는 배열
int candy[100], pos[100];

// 좌표에 따른 사탕 개수 저장용 배열
// pos에 저장된 바구니의 위치는 0-base이지만 101개의 값을 가질 수 있으므로 101로 크기 설정
int location[101] = {0, };

// 가장 오른쪽에 있는 사탕의 위치
int maxRight = 0;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> candy[i] >> pos[i];
        maxRight = max(maxRight, pos[i]);
    }

    for (int i = 0; i < N; i++) {
        location[pos[i]] += candy[i];
    }

    int result = 0;

    // cout << "중앙값 c의 위치" << '\n';
    // cout << "leftest : " << K + 1 << '\n';
    // cout << "rightest : " << maxRight - K + 1 << '\n';
    for (int i = K; i <= maxRight - K + 1; i++){
        int temp = 0;
        // cout << "(c - K) ~ (c + k)의 범위" << '\n';
        // cout << i - K << " ~ " << i + K << '\n';
        for (int j = i - K; j <= i + K; j++){
            temp += location[j];
        }

        result = max(result, temp);
    }

    cout << result;

    return 0;
}