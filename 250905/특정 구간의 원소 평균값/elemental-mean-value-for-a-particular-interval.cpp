#include <iostream>

using namespace std;

int n;
int arr[100];

bool isContained (double a, int left, int right){
    for (int i = left; i <= right; i++){
        if (arr[i] == a) return true;
    }

    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += arr[k];
            }
            double avg = (double)sum / (j - i + 1);

            if(isContained(avg, i, j)) result++;
        }
    }

    cout << result;

    return 0;
}