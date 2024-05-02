#include <iostream>
using namespace std;

int n,m,t,r,c;
int input[20][20];
int nextCount[20][20];
int Count[20][20];

int marbles=0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int n, int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n);
}

void f(){
    
    int max=input[r][c];
    for(int i=0;i<4;i++){
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(inRange(n, nx, ny) && max < input[nx][ny]){
            r = nx;
            c = ny;
            max = input[r][c];
            nextCount[r][c]++;
            break;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            Count[i][j] = nextCount[i][j];
        }
    }
    

    int nextMarbles=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(Count[i][j]==1){
                nextMarbles++;
            }
        }
    }
    m = nextMarbles;
}

int main() {
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }

    for(int i=0;i<t;i++){
        for(int i=0; i<m; i++){
            cin>>r>>c;
            f();
        }
    }

    cout<<m;
    
    
    return 0;
}