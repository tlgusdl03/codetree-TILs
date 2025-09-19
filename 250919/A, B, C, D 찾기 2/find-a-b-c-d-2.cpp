#include <iostream>
#include <algorithm>
using namespace std;

int nums[15];

int main() {
    for (int i = 0; i < 15; i++) {
        cin >> nums[i];
    }

    sort (nums, nums + 15);

    int A = nums[0];
    int ABCD = nums[14];
    
    for (int i = 1; i < 14; i++) {
        for (int j = i; j < 14; j++) {
            for (int k = j; k < 14; k++) {
                int B = nums[i];
                int C = nums[j];
                int D = nums[k];

                
                int arr[15] = {
                    A, B, C, D, A + B, B + C, C + D, D + A, A + C, B + D, A + B + C, A + B + D, A + C + D, B + C + D, A + B + C + D
                };

                sort (arr, arr + 15);

                bool pass = true;
                for (int l = 0; l < 15; l++) {
                    if (nums[l] != arr[l]) {
                        pass = false;
                        break;
                    }
                }

                if (pass) {
                    cout << A << " " << B << " " << C << " " << D << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}