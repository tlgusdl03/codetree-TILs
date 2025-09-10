#include <iostream>

using namespace std;

int N, B;
int P[1000];

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int result = 0;

    for (int i = 0; i < N; i++) {
        int count = 0;
        int totalPrice = 0;
        for (int j = 0; j < N; j++) {
            int price = (i == j)? P[j] / 2 : P[j];

            totalPrice += price;

            if (totalPrice > B) {
                break;
            }
            else {
                count++;
            }
        }
        result = max(result, count);
    }

    cout << result;

    return 0;
}