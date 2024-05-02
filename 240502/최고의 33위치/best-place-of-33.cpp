#include <iostream>
using namespace std;

int N;
int input[20][20];
int maxCount;


int main() {
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>input[i][j];
        }
    }

    for(int i=0; i<N-2; i++){
        for(int j=0; j<N-2; j++){
            int tempCount = 0;
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    tempCount += input[i + k][j + l];
                }
            }

            if(tempCount > maxCount){
                maxCount = tempCount;
            }
        }
    }

    cout<<maxCount<<'\n';
    return 0;
}