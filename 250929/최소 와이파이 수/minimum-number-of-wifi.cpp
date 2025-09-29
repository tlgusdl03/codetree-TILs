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

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            if (m != 0) {
                i += m + 1;
            }
            result++;
        }
    }

    cout << result;

    return 0;
}