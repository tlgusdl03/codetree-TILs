#include <iostream>

using namespace std;

int N;
int arr[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    int result = 0;
    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N; j++){
            for (int k = 0; k < N - 2; k++){
                for (int l = 0; l < N - 2; l++){
                    int temp = arr[i][k] + arr[i][k + 1] + arr[i][k + 2] + arr[j][l] + arr[j][l + 1] + arr[j][l + 2];
                    result = max(result, temp);
                }
            }
        }
    }

    cout << result;

    return 0;
}