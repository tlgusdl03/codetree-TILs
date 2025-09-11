#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

struct EatLogs {
    int p, m, t;
};

struct SickLogs {
    int p, t;
};

int N, M, D, S;

vector<EatLogs> eatLogs;
vector<SickLogs> sickLogs;

set<int> sickPeople;

bool rottenCheese[51] = {false, };

bool ateCheese(int cheese, int sick_p, int sick_t) {
    for (int i = 0; i < D; i++) {
        if(eatLogs[i].m == cheese && eatLogs[i].p == sick_p  && eatLogs[i].t < sick_t) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        int p, m, t;
        cin >> p >> m >> t;
        eatLogs.push_back({p, m, t});
    }

    for (int i = 0; i < S; i++) {
        int sick_p, sick_t;
        cin >> sick_p >> sick_t;
        sickLogs.push_back({sick_p, sick_t});
    }

    // 상한 치즈를 추론하는 과정
    for (int i = 1; i <= 50; i++) {
        // i번 치즈가 상했다 가정함
        bool rotten = true;
        for (int j = 0; j < S; j++) {
            // 아픈 모든 사람들이 아프기 이전에 i번 치즈를 먹었는지 확인함
            int p = sickLogs[j].p;
            int t = sickLogs[j].t;

            // 만약 한명이라도 치즈를 아프기전 먹지 않았다면 상한 것이 아님
            if(!ateCheese(i, p, t)) {
                rotten = false;
                break;
            }
        }

        if(rotten) {
            rottenCheese[i] = true;
        }
    }

    // 상한 치즈를 먹은 전체 인원 계산
    for (int i = 1; i <= N; i++) {
        if (rottenCheese[i]) {
            for (auto eatLog : eatLogs) {
                if (eatLog.m == i) sickPeople.insert(eatLog.p);
            }
        }
        
    }

    cout << sickPeople.size();
    return 0;
}