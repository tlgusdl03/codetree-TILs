#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<int> v;

int main() {
    int n;
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int answer = INT_MAX;

    for (int i = 0; i < n; i++) {
        int total_distance = 0;
        for (int j = 0; j < n; j++) {
            total_distance += abs(j - i) * v[j];
        }

        answer = min(answer, total_distance);
    }

    cout << answer;

    return 0;
}