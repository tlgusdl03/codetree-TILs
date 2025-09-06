#include <iostream>

using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

bool getDiff(int a, int b) {
    return (abs(a - b) <= 2 || min(a, N - a) + min(b, N - b) <= 2);
}
     
int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if ((getDiff(i,  a1) && getDiff(j, b1) && getDiff(k, c1))
                || (getDiff(i, a2) && getDiff(j, b2) && getDiff(k, c2))) result++;
            }
        }
    }

    cout << result;

    return 0;
}