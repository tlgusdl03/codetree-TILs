#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void print_result() {
    for (int i = 0 ; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void choose(int idx) {
    if (idx == n) {
        print_result();
        return;
    }

    for (int i = 1; i <= k; i++) {
        if (idx >= 2 && v[idx - 2] == i && v[idx - 1] == i) continue;

        v.push_back(i);
        choose(idx + 1);
        v.pop_back();
    }
}

int main() {
    cin >> k >> n;

    choose(0);

    return 0;
}