#include <iostream>
using namespace std;

int n,t,x,y;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
char dir;

bool inRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int get_dir(char d){
    if(d=='R'){
        return 0;
    }
    else if(d=='D'){
        return 1;
    }
    else if(d=='U'){
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    cin>>n>>t;
    cin>>x>>y>>dir;
    x--;
    y--;
    int dir_n = get_dir(dir);

    for(int i=0; i<t;i++){
        int nx = x + dx[dir_n];
        int ny = y + dy[dir_n];
        if(inRange(nx, ny, n)){
            x = nx;
            y = ny;
        }
        else {
            dir_n = 3 - dir_n;
        }
    }
    
    cout<<x + 1<<' '<<y + 1<<'\n';    
    return 0;
}