#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int c, n;
int arr[10][20];
int results[20][20] = {0,};
int main() {
    cin >> c >> n;

    for (int i = 0; i < c; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                results[arr[i][j]][arr[i][k]]++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++){
            if(i != j && results[i][j] == c) count++;
        }
    }

    cout << count;

    return 0;
}