#include <iostream>
using namespace std;
int n,m,x,y,dir=0;
char count = 'A';
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char a[100][100];

bool inRange(int x, int y, int n, int m){
    return(0 <= x && x < n && 0 <= y && y < m);
}

int main() {
    cin>>n>>m;

    for(int i=0;i < n * m;i++){
        a[x][y] = count;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!inRange(nx, ny, n, m) || a[nx][ny] != 0){
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
        count++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}