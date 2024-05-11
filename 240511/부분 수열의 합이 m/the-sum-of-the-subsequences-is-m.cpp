#include <iostream>
#include <algorithm>

#define MAX_M 10000
#define MAX_N 100
#define MAX_ANS 101

using namespace std;

int n, m;
int arr[MAX_N];

int dp[MAX_M + 1];

void Initialize(){
    for(int i = 0; i <= m; i++){
        dp[i] = MAX_ANS;
    }
    dp[0] = 0;
}

void Simulate(){
    for(int i=0; i<n; i++){
        for(int j=m; j>=0; j--){
            if(j >= arr[i]){
                dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            }
        }
    }
}
int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Initialize();

    Simulate();

    int ans = dp[m];

    if(ans == MAX_ANS){
        ans = -1;
    }

    cout<<ans;
    return 0;
}