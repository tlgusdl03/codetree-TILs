#include <iostream>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
    }

    int result = 0;

    for (int i = 0; i <= 1000; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (i < Ta[j]) {
                temp += C;
            }
            else if (Ta[j] <= i && i <= Tb[j]) {
                temp += G;
            }
            else if (Tb[j] < i) {
                temp += H;
            }
        }

        result = max(result, temp);
    }

    cout << result;
    return 0;
}