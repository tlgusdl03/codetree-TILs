#include <iostream>
#include <queue>
using namespace std;

int n, m;
int answer = -1;
bool input[100][100];
bool isVisited[100][100];
int step[100][100];
queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void push(int x, int y, int s){
    step[x][y] = s;
    isVisited[x][y] = true;
    q.push(make_pair(x,y));
}

bool canGo(int x, int y){
    return (0<=x&&x<n&&0<=y&&y<m&&input[x][y]&&!isVisited[x][y]);
}

void BFS(){
    while(!q.empty()){
        pair<int, int> curr_v = q.front();
        q.pop();
        int x = curr_v.first;
        int y = curr_v.second;
        if(x == n-1 && y == m-1){
            answer = step[n-1][m-1];
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(canGo(nx, ny)){
                push(nx,ny,step[x][y]+1);
            }
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>input[i][j];
        }
    }

    push(0,0,0);
    BFS();
    cout<<answer<<'\n';
    return 0;
}