#include <iostream>
using namespace std;
int n,x,y,dir=2;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int a[100][100];

bool inRange(int x, int y, int n){
    return(0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin>>n;
    int count = n * n;
    x = n-1;
    y = x;

    for(int i=0;i < n * n;i++){
        a[x][y] = count;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!inRange(nx, ny, n) || a[nx][ny] != 0){
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
        count--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}