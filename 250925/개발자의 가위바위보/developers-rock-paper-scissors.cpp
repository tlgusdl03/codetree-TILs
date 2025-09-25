#include <iostream>

using namespace std;

int N;
int a[100], b[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    int result = 0;

    for (int i = 1; i <= 3; i++) {
        // i : 가위의 번호
        for (int j = 1; j <= 3; j++) {
            // j : 바위의 번호
            for (int k = 1; k <= 3; k++) {
                // k : 보의 번호
                if (i == j || j == k || i == k) continue;

                int temp = 0;

                for (int l = 0; l < N; l++) {
                    int A = a[l];
                    int B = b[l];

                    if ((A == i && B == k) || (A == j && B == i) || (A == k && B == j)) temp++;
                    
                }

                result = max(result, temp);
            }   
        }
    }

    cout << result;

    return 0;
}