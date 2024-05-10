#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100

int n;
int num[MAX][MAX];
int dp[MAX][MAX];

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num[i][j];
        }
    }
 
    dp[0][0] = num[0][0];
    
    for(int i = 1; i < n; i++){
        dp[0][i] = dp[0][i-1] + num[0][i]; 
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + num[i][0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j-1]) + num[i][j];
        }
    }
}

int main() {
    cin>>n;

    init();
    cout<<dp[n-1][n-1]<<'\n';
    return 0;
}