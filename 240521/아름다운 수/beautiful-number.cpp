#include <iostream>
using namespace std;

int n;
int backTrackingArr[10];
long long ans;

void check_beatiful(){
    int index=0;
    while(index < n){
        int temp = backTrackingArr[index];
        for(int i=0;i<temp;i++){
            if(index + i >= n || backTrackingArr[index + i] != temp){
                return;
            }
        }
        index += temp;
    }
    ans++;
}
void backTracking(int count){
    if(count == n){
        check_beatiful();
    }
    else {
        for(int i=1; i<=4; i++){
            backTrackingArr[count]=i;
            backTracking(count + 1);
        }
    }
}
int main() {
    cin>>n;
    backTracking(0);
    cout<<ans;
    return 0;
}