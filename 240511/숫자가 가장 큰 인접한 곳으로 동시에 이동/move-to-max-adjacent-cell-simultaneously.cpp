#include <iostream>
using namespace std;
#define DIR_NUM 4
#define MAX_N 20

int t, n, m;

int a[MAX_N][MAX_N];
int count[MAX_N][MAX_N];
int next_count[MAX_N][MAX_N];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

pair<int, int> GetMaxNeighborPos(int x, int y){
    int max_num=0;
    pair<int,int> max_pos;

    for(int i = 0; i < DIR_NUM; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inRange(nx, ny) && a[nx][ny] > max_num){
            max_num = a[nx][ny];
            max_pos = make_pair(nx, ny);
        }
    }

    return max_pos;
}

void Move(int x, int y){
    pair<int, int> next_pos = GetMaxNeighborPos(x, y);
    int next_x = next_pos.first, next_y = next_pos.second;

    next_count[next_x][next_y]++;
}

void MoveAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            next_count[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(count[i][j] == 1){
                Move(i,j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            count[i][j] = next_count[i][j];
        }
    }
}

void RemoveDuplicateMarbles(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(count[i][j] >= 2){
                count[i][j] = 0;
            }
        }
    }
}

void Simulate(){
    MoveAll();
    RemoveDuplicateMarbles();
}

int main() {
    cin>>n>>m>>t;

    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    //초기에 count 배열을 구슬의 초기 위치로 초기화 시켜주어야 함
    //t 초 동안 시뮬레이션을 돌린 후 충돌난 구슬은 없애야 함
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        count[x-1][y-1] = 1;
    }

    //count 배열을 돌면서 구슬의 개수를 확인한 후 출력함
    for(int i=0;i<t;i++){
        Simulate();
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += count[i][j];
        }
    }
    
    cout<<ans;
    return 0;
}