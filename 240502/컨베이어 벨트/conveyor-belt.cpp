#include <iostream>
using namespace std;

int n, t;
int input1[200];
int input2[200];

int main() {
    cin>>n>>t;

    for(int i=0;i<n;i++){
        cin>>input1[i];
    }

    for(int i=0;i<n;i++){
        cin>>input2[i];
    }

    for(int i=0;i<t;i++){
        int temp1 = input1[n - 1];
        int temp2 = input2[n - 1];
        for(int j=n-1; j>0; j--){
            input1[j] = input1[j-1];
        }
        input1[0] = temp2;
        for(int j=n-1; j>0; j--){
            input2[j] = input2[j-1];
        }
        input2[0] = temp1;
    }
    
    for(int i=0;i<n;i++){
        cout<<input1[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<input2[i]<<' ';
    }
    return 0;
}