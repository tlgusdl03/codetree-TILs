#include <iostream>
using namespace std;
int n, m;
int count=0;

int a[100][100];
int main() {
    cin>>n>>m;
    // 배열 입력부
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    // 행 확인부
    for(int i=0; i<n; i++){
        int temp=1;
        for(int j=1; j<n; j++){
            if(a[i][j] == a[i][j-1]){
                temp++;
            }
            else{
                temp=1;
            }
        }
        if(m <= temp){
            count++;
        }

    }

    // 열 확인부
    for(int i=0; i<n; i++){
        int temp=1;
        for(int j=1; j<n; j++){
            if(a[j][i] == a[j-1][i]){
                temp++;
            }
            else{
                temp=1;
            }
        }
        if(m <= temp){
            count++;
        }

    }
    

    cout<<count++;
    return 0;
}