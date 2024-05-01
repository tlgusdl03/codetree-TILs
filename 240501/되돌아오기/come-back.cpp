#include <iostream>
using namespace std;

int x, y, n, dir, dis, sec=0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir_c;

bool inRange(int x, int y, int n){
    return (0 <= x && x < n && 0 <= y && y < n);
}

int get_dir(char d){
    if(d=='E'){
        return 0;
    }
    else if(d=='S'){
        return 1;
    }
    else if(d=='W'){
        return 2;
    }
    else{
        return 3;
    }
}

int main() {
    
    cin>>n;

    for(int i=0; i<n;i++){
        cin>>dir_c>>dis;
        dir=get_dir(dir_c);

        for(int j=0;j<dis;j++){
            x = x + dx[dir];
            y = y + dy[dir];
            sec++;
            if(x==0 && y==0){
            cout<<sec<<'\n';
            return 0;
            }   
        }
    }

    cout<<-1<<'\n';

    return 0;
}