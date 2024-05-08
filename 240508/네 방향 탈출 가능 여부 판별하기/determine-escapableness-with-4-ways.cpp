#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool answer = false;
bool input[100][100];
bool isVisited[100][100];
queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool canGo(int x, int y){
    return (0<=x&&x<n&&0<=y&&y<m&&input[x][y]&&!isVisited[x][y]);
}

void BFS(){
    while(!q.empty()){
        pair<int, int> curr_v = q.front();
        q.pop();
        if(curr_v.first == n-1 && curr_v.second == m-1){
            answer = true;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = curr_v.first + dx[i];
            int ny = curr_v.second + dy[i];
            if(canGo(nx, ny)){
                isVisited[nx][ny] = true;
                q.push(make_pair(nx, ny));
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

    q.push(make_pair(0,0));
    isVisited[0][0] = true;
    BFS();
    cout<<answer<<'\n';
    return 0;
}