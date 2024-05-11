#include<iostream>
#define MAX_LEN 400
using namespace std;

int input[MAX_LEN];
int n, t;

void simulate(){
    t = t % (2*n);
    int last_index = 2 * n - 1; 
    int temp = input[last_index];

    for(int i=0;i<t;i++){
        for(int j=2*n-1; j>=1; j--){
            input[j] = input[j-1];
        }
        input[0] = temp;
    }
}

int main(){
    cin>>n>>t;
    for(int i=0; i<2*n; i++){
        cin>>input[i];
    }

    simulate();

    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cout<<input[i * n + j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}