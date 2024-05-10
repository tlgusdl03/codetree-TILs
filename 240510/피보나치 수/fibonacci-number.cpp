#include <iostream>
using namespace std;

int n;
int DP[45];

void F(int n){
    DP[0] = 1;
    DP[1] = 1;
    for(int i=2; i<n; i++){
        DP[i] = DP[i-1] + DP[i-2];
    }
}

int main() {
    cin>>n;
    F(n);
    cout<<DP[n-1]<<'\n';
    return 0;
}