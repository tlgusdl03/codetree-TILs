#include <iostream>
#include <algorithm>
using namespace std;

int arr[7];

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 7);

    int a = arr[0];
    int b = arr[1];
    
    int abc = arr[6];

    int c = abc - a - b;

    cout << a << " " << b << " " << c;



    return 0;
}