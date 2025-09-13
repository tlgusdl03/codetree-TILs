#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int left = a[0];
    int right = a[n - 1];

    int result = 0;

    for (int i = left; i <= right; i++) {
        int temp = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i - a[j]) == (a[k] - i)) temp++;
            }
        }
        result = max(result, temp);
    }

    cout << result;

    return 0;
}