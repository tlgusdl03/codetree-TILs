#include <iostream>
using namespace std;
int n;
int arr[100];


void insertion_sort(){
    for(int i=1; i<n; i++){
        int j=i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key){
            swap(arr[j+1], arr[j]);
            j--;
        }
    }
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertion_sort();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    
    return 0;
}