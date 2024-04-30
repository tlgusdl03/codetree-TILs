#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int x=0, y=0;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin>>n;

    char dir;
    int distance;

    for(int i=0;i<n;i++){
        cin>>dir>>distance;

        if(dir=='W'){
            x += dx[2]*distance;
        }
        else if(dir == 'N'){
            y += dy[3]*distance;
        }
        else if(dir == 'E'){
            x += dx[0]*distance;
        }
        else if(dir == 'S'){
            y += dy[1]*distance;
        }
    }

    cout<<x<<' '<<y<<'\n';
    return 0;
}