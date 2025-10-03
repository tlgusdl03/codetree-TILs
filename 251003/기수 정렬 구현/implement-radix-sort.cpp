#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[100000];

void radix_sort(int arr[], int n) {
    int radix = 1;
    for (int i = 0; i < 6; i++) {
        vector<int> new_arr[10];
        for (int j = 0; j < n; j++) {
            int digit = arr[j] / radix % 10;
            new_arr[digit].push_back(arr[j]);
        }
        
        radix *= 10;

        int idx = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < new_arr[j].size(); k++) {
                arr[idx++] = new_arr[j][k];
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radix_sort(arr, n);

    for (int i = 0 ; i < n; i++) {
        cout << arr[i] <<  " ";
    }

    return 0;
}
