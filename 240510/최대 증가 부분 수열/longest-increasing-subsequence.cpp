#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000

int n;

int num[MAX];
int dp[MAX];


void init(){
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

void F(){
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(num[j]<num[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
};
int main() {
    cin>>n;
    init();
    F();
    cout<<dp[n-1]<<'\n';
    return 0;
}