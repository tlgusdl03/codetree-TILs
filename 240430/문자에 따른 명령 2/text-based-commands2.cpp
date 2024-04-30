#include <iostream>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int x=0, y=0;

int main() {
    
    string input;
    cin>>input;
    int dir=3;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == 'L'){
            dir = (dir - 1 + 4) % 4;
        }
        else if(input[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        else if(input[i] == 'F'){
            x += dx[dir];
            y += dy[dir];
        }
    }

    cout<<x<<' '<<y<<'\n';
    return 0;
}