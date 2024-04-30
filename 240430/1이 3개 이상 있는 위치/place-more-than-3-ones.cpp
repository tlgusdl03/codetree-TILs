#include <iostream>
using namespace std;

int n;
int count;
int dir=3;
int input[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool InRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tempCnt=0;
            for(int dir_num = 0; dir_num < 4; dir_num++) {
                int nx = i + dx[dir_num], ny = j + dy[dir_num];
                
                if(InRange(nx, ny, n) && input[nx][ny] == 1)
                    tempCnt++;
            }
            if(3 <= tempCnt){
                count++;
            }
        }
    }

    cout<<count<<'\n';
    return 0;
}