#include<iostream>
#define MAX 20
using namespace std;

int n;
int ans;
int input[MAX][MAX];


void simulate(int x, int y){
    int count=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            count += input[x + i][y + j];
        }
    }
    if(ans < count){
        ans = count;
    }
}

void simulateAll(){
    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-2; j++){
            simulate(i,j);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }

    simulateAll();

    cout<<ans<<'\n';
    return 0;
}