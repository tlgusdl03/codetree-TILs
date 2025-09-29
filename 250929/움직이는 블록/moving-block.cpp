#include <iostream>

using namespace std;

int n;
int blocks[10000];
int total = 0;
int same = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
        total += blocks[i];
    }

    same = total / n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        if (blocks[i] > same) {
            result += blocks[i] - same;
        }
    }

    cout << result;

    return 0;
}