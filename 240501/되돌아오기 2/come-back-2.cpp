#include <iostream>
#include <string>
using namespace std;

int x,y,n,dir=3,sec=0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string dir_c;


int main() {
    cin>>dir_c;

    for(int i=0; i<dir_c.length(); i++){
        if(dir_c[i]=='L'){
            dir = (dir - 1 + 4) % 4;
        }
        else if(dir_c[i]=='R'){
            dir = (dir + 1) % 4;
        }
        else {
            x = x + dx[dir];
            y = y + dy[dir];
        }

        sec++;

        if(x == 0 && y == 0){
            cout<<sec<<'\n';
            return 0;
        }
    }

    cout << -1 <<'\n';
    return 0;
}