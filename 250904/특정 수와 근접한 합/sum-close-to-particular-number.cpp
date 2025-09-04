#include <iostream>
#define max
using namespace std;

int N, S;
int arr[100];

int calSum (int a, int b){
    int result = 0;
    for (int i = 0; i < N; i++){
        if (i == a || i == b) continue;
        result += arr[i];
    }

    return result;
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 10001;

    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N; j++){
            result = min(result, abs(S - calSum(i , j)));
        }
    }

    cout << result;

    return 0;
}