#include <iostream>
using namespace std;
int n;
int arr[100];

void select_sort(){
    for(int i=0; i<n; i++){
        int min = 101;
        int min_index=-1;
        for(int j=i; j<n; j++){
            if(min > arr[j]){
                min = arr[j];
                min_index = j;
            }
        }
        if(min_index != -1){
            swap(arr[i], arr[min_index]);
        }
    }
    return;
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    select_sort();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}