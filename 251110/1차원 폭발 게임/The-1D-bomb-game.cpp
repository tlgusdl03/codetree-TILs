#include <iostream>

using namespace std;

int n, m;
int numbers[100];

// 0 - index 기반 M개 이상 연속된 숫자를 0으로 변환하는 함수
void bomb(int startIdx, int endIdx) {
    for (int i = startIdx; i <= endIdx; i++) {
        numbers[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    while (true) {
        // 1개 이상의 폭탄이 터져 배열 압축이 필요한 경우 과정을 반복 하기 위한, 상태 추적 변수
        bool pass = true;

        // 폭탄 무리의 첫번째 인덱스
        int firstIdx = 0;

        // 한 폭탄 무리의 포함된 폭탄의 수
        int count = 0;


        for (int i = 0; i < n; i++) {
            // 현재 원소가 0이 아니고, 현재 추적하고 있는 무리와 같다면 개수 증가
            if (numbers[firstIdx] == numbers[i] && numbers[i] != 0) {
                count++;
            }

            // 다르다면 개수를 확인 한 후 처리
            else if (numbers[firstIdx] != numbers[i]) {
                if (count >= m) {
                    bomb(firstIdx, i - 1);
                    pass = false;
                }
                count = 1;
                firstIdx = i;
            }
        }

        // 마지막 그룹에 대해 처리
        if (count >= m) {
            bomb(firstIdx, n - 1);
            pass = false;
        }

        // 남아있는 원소들만 배열 압축하여 numbers 배열 갱신
        int idx = 0;
        int temp[100] = {0, };

        for (int i = 0; i < n; i++) {
            if (numbers[i] != 0) {
                temp[idx] = numbers[i];
                idx++;
            }
        }

        for (int i = 0; i < n; i++) {
            numbers[i] = temp[i];
        }

        // 터질 폭탄이 없다면 종료
        if (pass) break;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] != 0) {
            result++;
        }
    }

    cout << result << '\n';

    for (int i = 0; i < n; i++) {
        if (numbers[i] != 0) {
            cout << numbers[i] << '\n';
        }
    }

    return 0;
}
