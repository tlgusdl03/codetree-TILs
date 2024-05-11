#include<iostream>
#define MAX 20
#define DIR_NUM 4
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1};

int n,m,t;
int a[MAX][MAX];
int count[MAX][MAX];
int next_count[MAX][MAX];

bool inRange(int x, int y){
    return(0 <= x && x < n && 0 <= y && y < n);
}

void removeDuplicative(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(count[i][j] >= 2){
                count[i][j] = 0;
            }
        }
    }
}

pair<int, int> getNextPos(int x, int y){
    int max_num=0;
    pair<int, int> max_pos;

    for(int i=0; i<DIR_NUM; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inRange(nx, ny) && max_num < a[nx][ny]){
            max_num = a[nx][ny];
            max_pos = make_pair(nx, ny);
        }
    }
    return max_pos;
}

void move(int x, int y){
    pair<int, int> next_pos = getNextPos(x, y);
    int nx = next_pos.first;
    int ny = next_pos.second;

    next_count[nx][ny]++;
}

void moveAll(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            next_count[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(count[i][j] == 1){
                move(i, j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            count[i][j] = next_count[i][j];
        }
    }
}

void simulate(){
    moveAll();
    removeDuplicative();
}

int main(){
    int ans=0;

    cin>>n>>m>>t;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int r, c;
        cin>>r>>c;
        r--; c--;
        count[r][c] = 1;
    }

    while(t--){
        simulate();
    }

    for(int i=0; i<n; i++){
        for(int j=0 ;j<n; j++){
            if(count[i][j] == 1){
                ans++;
            }
        }
    }

    cout<<ans<<'\n';
    return 0;
}