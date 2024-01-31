#include <iostream>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int arr[10000] = {0,};
    int index = 0;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string order;
        cin>>order;
        if(order == "push_back"){
            int n;
            cin>>n;
            arr[index] = n;
            index++;
        }
        else if(order == "pop_back"){
            index--;
        }
        else if(order == "size"){
            cout<<index<<'\n';
        }
        else if(order == "get"){
            int temp;
            cin>>temp;
            cout<< arr[temp-1]<<'\n';
        }
    }
    return 0;
}