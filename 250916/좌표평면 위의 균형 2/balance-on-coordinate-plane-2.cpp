#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[100], y[100];

int getResult(int a, int b) {
    int area1 = 0, area2 = 0, area3 = 0, area4 = 0;
    
    for (int i = 0; i < n; i++) {
        if (x[i] > a && y[i] > b) area1++;
        else if (x[i] < a && y[i] > b) area2++;
        else if (x[i] < a && y[i] < b) area3++;
        else if (x[i] > a && y[i] < b) area4++; 
    }

    return max({area1, area2, area3, area4});
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int result = 100;

    for (int i = 2; i <= 100; i += 2) {
        for (int j = 2; j <= 100; j += 2) {
            result = min(result, getResult(i, j));
        }
    }

    cout << result;

    return 0;
}