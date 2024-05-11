#include<iostream>
#define MAX 100
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, r, c;
int numbers[MAX][MAX];

bool inRange(int x, int y){
    return(0 <= x && x < n && 0 <= y && y < n);
}

void simulate(){
    while(true){
        bool isMove = false;
        int current = numbers[r][c];
        cout<<current<<' ';
        for(int i=0; i<4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(inRange(nx, ny) && current < numbers[nx][ny]){
                r=nx;
                c=ny;
                isMove = true;
                break;
            }
        }
        if(!isMove){
            return;
        }
    }
}

int main(){
    cin>>n>>r>>c;
    r--,c--;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>numbers[i][j];
        }
    }
    simulate();
    return 0;
}