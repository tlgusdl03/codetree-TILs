#include<iostream>
#define MAX 100
using namespace std;

int n;
int input[MAX];

int end_of_array;

void CutArray(int s, int e){
    int temp_arr[MAX];
    int end_of_temp_array = 0;

    for(int i = 0; i < end_of_array; i++){
        if(i < s || i > e){
            temp_arr[end_of_temp_array++] = input[i];
        }
    }

    for(int i = 0; i < end_of_temp_array; i++){
        input[i] = temp_arr[i];
    }

    end_of_array = end_of_temp_array;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin>> input[i];
    }

    end_of_array = n;

    for(int k = 0; k < 2; k++){
        int s, e;
        cin>>s>>e; s--; e--;
        CutArray(s,e);
    }

    cout<<end_of_array<<'\n';
    for(int i=0; i < end_of_array; i++){
        cout << input[i] << '\n';
    }

    return 0;
}