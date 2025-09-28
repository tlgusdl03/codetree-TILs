#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int result = -1000000000;
    
    // 1. 0이 포함된 경우 -> 0이 최대

    // 2. 음수 2개 양수 1개로 구성된 경우

    // 3. 양수로만 구성된 경우

    result = max(arr[0] * arr[1] * arr[n - 1], arr[n - 3] * arr[n - 2] * arr[n - 1]);

    cout << result;

    return 0;
}