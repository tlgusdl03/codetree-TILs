#include <iostream>
#define MAX_R 200050
#define OFFSET 100025
#define N 1000
using namespace std;

int n;
int x1[N];
int x2[N];
char directions[N];

int main() {
    cin >> n;

    int current = 0;
    for (int i = 0; i < n; i++) {
        int distance;
        char direction;

        cin >> distance >> direction;

        if(direction == 'L'){
            x1[i] = current - distance + 1;
            x2[i] = current;
            current = x1[i];
        }
        else if(direction == 'R'){
            x1[i] = current;
            x2[i] = current + distance -1;
            current = x2[i];
        }

        x1[i] += OFFSET;
        x2[i] += OFFSET;
        directions[i] = direction;
    }

    int whiteNums[MAX_R] = {0,};
    int blackNums[MAX_R] = {0,};
    char colors[MAX_R];

    for(int i = 0; i < MAX_R; i++){
        colors[i] = 'M';
    }

    for(int i = 0; i < n; i++){
        for(int j = x1[i]; j <= x2[i]; j++){
            if(colors[j] == 'G') continue;

            if(directions[i] == 'L'){
                whiteNums[j]++;
                colors[j] = 'W';
            }
            else if(directions[i] == 'R'){
                blackNums[j]++;
                colors[j] = 'B';
            }

            if(whiteNums[j] >= 2 && blackNums[j] >= 2){
                colors[j] = 'G';
            }
        }
    }

    int whiteCount = 0;
    int blackCount = 0;
    int grayCount = 0;
    for(int i = 0; i < MAX_R; i++){
        if(colors[i] == 'W') whiteCount++;
        else if(colors[i] == 'B') blackCount++;
        else if(colors[i] == 'G') grayCount++;
    }

    cout << whiteCount << ' ' << blackCount << ' ' << grayCount;

    return 0;
}