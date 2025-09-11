#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

/* 
사람의 수 : N
치즈의 종류: M
치즈를 먹은 기록의 수 : D
아픈 기록의 수 : S

N개의 기록
( p, m, t )

S개의 기록
( p, t )

여러 사람이 1 종류의 치즈를 여러번 먹을 수 있음
한 사람이 여러 종류의 치즈를 먹을 수 있음

S개의 데이터를 이용하여 p가 t 이전에 먹은 치즈를 상한 치즈로 규정
이후 상한 치즈를 먹은 사람을 추척

1-base의 2차원 배열을 이용하여 누가 언제 어떤 치즈를 먹었는지 관리
*/

struct SickData {
    int p, t;
};

int N, M, D, S;
vector<SickData> sickDatas;
// 치즈 섭취 관리 배열
int eatDatas[51][51] = {0, };
// 상한 치즈 목록
set<int> rottenCheese;
// 아픈 사람 목록
set<int> sickPeople;

int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        int p, m, t;
        cin >> p >> m >> t;
        eatDatas[p][m] = t;
    }

    for (int i = 0; i < S; i++) {
        int sick_p, sick_t;
        cin >> sick_p >> sick_t;
        sickDatas.push_back({sick_p, sick_t});
    }

    for (int i = 0; i < S; i++) {
        int p = sickDatas[i].p;
        int t = sickDatas[i].t;

        for (int j = 1; j <= M; j++) {
            if (eatDatas[p][j] > 0 && eatDatas[p][j] < t) {
                rottenCheese.insert(j);
            }
        }
    }

    // 상한 치즈를 먹은 전체 인원 계산
    for (auto cheese : rottenCheese) {
        for (int i = 1; i <= N; i++) {
            if (eatDatas[i][cheese] > 0) {
                sickPeople.insert(i);
            }
        }
    }

    cout << sickPeople.size();
    return 0;
}