#include <iostream>
using namespace std;

int N, K;
int answer[8];

void choose(int current_index){
    if(current_index == N){
        for(int i=0;i<N;i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    else{
        for(int i=1;i<=K;i++){
            if(current_index == 0 || !((answer[0] == answer[1]) && (answer[1] == i)))
            {
                answer[current_index]=i;
                choose(current_index+1);
            }
        }
    }
}
int main() {
    cin>>K>>N;
    choose(0);
    return 0;
}