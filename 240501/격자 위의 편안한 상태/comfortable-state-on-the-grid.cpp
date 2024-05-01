#include <iostream>
using namespace std;

bool input[100][100];
int n, m, r, c;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y, int n){
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>r>>c;
        input[r-1][c-1] = true;
        int count=0;
        for(int j=0;j<4;j++){
            int nx = r-1 + dx[j];
            int ny = c-1 + dy[j];
            if(inRange(nx, ny, n) && input[nx][ny]){
                count++;
            }
        }
        if(count==3){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}