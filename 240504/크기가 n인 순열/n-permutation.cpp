#include <iostream>
using namespace std;

int N;
int answer[8];
bool isVisted[8];

void choose(int count){
    if(count==N){
        for(int i=0; i<N; i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
    }
    else{
        for(int i=1; i<=N;i++){
            if(!isVisted[i-1]){
                answer[count] = i;
                isVisted[i-1] = true;
                choose(count+1);
                isVisted[i-1]=false;
            }
        }
    }
}

int main() {
    cin>>N;
    choose(0);
    return 0;
}