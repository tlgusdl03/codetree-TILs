#include <iostream>
using namespace std;

int n;
int inputArr[100];

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>inputArr[i];
    }

    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i=0; i<n-1; i++){
            if(inputArr[i] > inputArr[i+1]){
                swap(inputArr[i], inputArr[i+1]);
                sorted = false;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<inputArr[i]<<' ';
    }
    return 0;
}