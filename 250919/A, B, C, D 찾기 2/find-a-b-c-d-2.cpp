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
    
    for (int i = 1; i <= 12; i++) {
        for (int j = 2; j <= 13; j++) {
            for (int k = 3; k <= 14; k++) {
                int B = nums[i];
                int C = nums[j];
                int D = nums[k];
                if (A + B + C + D == ABCD) {
                    cout << A << " " << B << " " << C << " " << D << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}