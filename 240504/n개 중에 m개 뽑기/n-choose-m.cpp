#include <iostream>
using namespace std;

int M, N;
int answer[10];

void choose(int count, int last){
    if(count == M){
        for(int i=0; i<M; i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    else{
        for(int i=1;i<=N;i++){
            if(last < i){
                answer[count]=i;
                choose(count+1, i);
            }
        }
    }
}
int main() {
    cin>>N>>M;
    choose(0,0);
    return 0;
}