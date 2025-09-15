#include <iostream>

using namespace std;

int N;
int a[100], b[100], c[100];

int getResult (int initPos) {
    int result = 0;
    int pos = initPos;

    for (int i = 0; i < N; i++) {
        if (a[i] == pos) pos = b[i];
        else if (b[i] == pos) pos = a[i];
        
        if (c[i] == pos) result++;
    }

    return result;
}  

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int result = 0;
    for (int i = 1; i <= 3; i++) {
        int temp = 0;
        temp = getResult(i);
        result = max(result, temp);
    }

    cout << result;

    return 0;
}