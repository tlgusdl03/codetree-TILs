#include <iostream>

using namespace std;

int n;
char arr[26];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = 0;

    while(true) {
        int temp = 0;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                temp++;
            }
        }

        if (temp == 0) break;

        result += temp;
    }

    cout << result;

    return 0;
}