#include <iostream>
using namespace std;

int n,r,c;
int input[100][100];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int n, int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

void f(){
    while(true){
        int max=input[r][c];
        bool isMove = false;
        cout<<input[r][c]<<' ';
        for(int i=0;i<4;i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(inRange(n, nx, ny) && max < input[nx][ny]){
                r = nx;
                c = ny;
                max = input[r][c];
                isMove = true;
                break;
            }
        }
        if(!isMove){
            return;
        }
    }
}

int main() {
    cin>>n>>r>>c;
    r--;c--;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }
    f();
    return 0;
}