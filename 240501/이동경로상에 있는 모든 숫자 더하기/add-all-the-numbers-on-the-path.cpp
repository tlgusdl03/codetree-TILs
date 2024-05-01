#include <iostream>
using namespace std;

int n,t,x,y,dir=3,count=0;
string dir_c;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int a[100][100];

bool inRange(int x, int y, int n){
    return(0 <= x && x < n && 0 <= y && y < n);
}

int main() {

    cin>>n>>t;

    x = n/2;
    y =n/2;

    cin>>dir_c;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    count += a[x][y];
    for(int i=0;i<t;i++){
        if(dir_c[i]=='R'){
            dir = (dir + 1) % 4;
        }
        else if(dir_c[i]=='L'){
            dir = (dir - 1 + 4) % 4;
        }
        else{
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(inRange(nx, ny, n)){
                x = nx;
                y = ny;
                count += a[x][y];
            }
        }
    }

    cout<<count<<'\n';
    return 0;
}