#include <iostream>
using namespace std;
int arr[20][20];
int N;
int max_num;

void find_max(int row, int col){
    int temp=0;
    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            temp += arr[row+i][col+j];
        }
    }
    if(temp>max_num){
        max_num = temp;
    }
}
int main() {
    cin>>N;

    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((i + 3) > N){
                continue;
            }
            else{
                find_max(i, j);
            }
        }
    }

    cout<<max_num<<'\n';
    return 0;
}