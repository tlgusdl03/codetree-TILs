#include <iostream>
using namespace std;

int n;
int memo[46];
int Fibbo(int n){
    if(memo[n] != -1){
        return memo[n];
    }
    if(n<=2){
        return memo[n] = 1;
    }
    else{
        memo[n] = Fibbo(n-1) + Fibbo(n-2);
        return memo[n];
    }
}

void initArray(int n, int a){
    for(int i=0;i<=n;i++){
        memo[i] = a;
    }
}

int main() {
    cin>>n;
    initArray(n, -1);
    int answer = Fibbo(n);
    cout<<answer<<'\n';
    return 0;
}