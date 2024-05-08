#include <iostream>
using namespace std;

bool input[100][100];
bool isVisited[100][100];
int n,m;
bool answer=false;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool canGo(int x, int y){
    return (0<=x&&x<n&&0<=y&&y<m&&input[x-1][y-1]&&!isVisited[x-1][y-1]);
}

void DFS(int x, int y){
    if(x==n-1 && y==m-1){
        answer = true;
        cout<<answer<<'\n';
        return;
    }
    else{
        for(int i=0;i<2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(canGo(nx, ny)){
                isVisited[nx][ny]=true;
                DFS(nx, ny);
            }
        }
    }
}


int main() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }
    isVisited[0][0]=true;
    DFS(0,0);
    cout<<0<<'\n';
    return 0;
}