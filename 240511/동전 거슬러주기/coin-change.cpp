#include <iostream>
using namespace std;
#define MAX_M 10000
#define MAX_N 100
#define MAX_ANS 10001

int n, m; //달성해야하는 금액 합: m, 동전의 종류의 개수: n
int dp[MAX_M + 1]; //금액 합이 i가 되었을 때 사용한 동전의 개수의 최대값
int coin[MAX_N];

void Initialize() {
    for(int i = 0; i <= m; i++){
        dp[i] = MAX_ANS;
    }
    dp[0] = 0;
}


void F(){
    for(int i=0; i<=m; i++){
        for(int j = 0; j < n; j++){
            if(i >= coin[j]){
                dp[i] = min(dp[i], dp[i-coin[j]] + 1);
            }
        }
    }
}

int main() {
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    Initialize();
    F();
    int ans = dp[m];
    if(ans == MAX_ANS){
        ans = -1;
    }
    cout<<ans<<'\n';
    return 0;
}