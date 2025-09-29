#include <iostream>

using namespace std;

int n, m;
int arr[100];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 0;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count > 0) {
            count--;
        }
        else if (arr[i] == 1) {
            count = 2 * m;
            result++;
        }
    }

    cout << result;

    return 0;
}