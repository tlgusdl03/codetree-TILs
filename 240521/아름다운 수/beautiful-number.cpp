#include <iostream>
using namespace std;

int n, ans;
int backTrackingArr[10];

void backTracking(int count){
    if(count == n){
        ans++;
    }
    else if (count < n){
        for(int i=1; i<=4; i++){
            int tempIdx = count;
            for(int j=0; j<i; j++){
                backTrackingArr[tempIdx] = i;
                tempIdx++;
            }
            backTracking(count + i);
        }
    }
}
int main() {
    cin>>n;
    backTracking(0);
    cout<<ans;
    return 0;
}