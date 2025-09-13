#include <iostream>
#include <set>
using namespace std;

int X, Y;

bool getResult (int i) {
    int arr[10] = {0, };
    set<int> includes;
    int length = 0;

    while (i > 0)  {
        arr[i % 10]++;
        includes.insert(i % 10);
        i /= 10;
        length++;
    }

    if (includes.size() != 2) return false;
    
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 0) continue;

        if (arr[i] > 0) {
            if (arr[i] != 1 && arr[i] != length - 1) return false;
        }
    }

    return true;
}

int main() {
    cin >> X >> Y;

    int result = 0;

    for (int i = X; i <= Y; i++) {
        if (getResult(i)) result++;
    }

    cout << result;

    return 0;
}