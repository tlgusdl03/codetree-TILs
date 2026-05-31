#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
int arr[3] = {4, 5, 6};
vector<int> v;

bool is_able() {
    int total_len = v.size();

    for (int len = 1; len <= total_len / 2; len++) {
        bool match = true;

        for (int i = 0; i < len; i++) {
            if (v[total_len - 1 - i] != v[total_len - 1 - len - i]) {
                match = false;
                break;
            }
        }

        if (match) return false;
    }

    return true;
}

void print_answer() {
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << '\n';
}

void choose(int idx) {
    if (idx == n) {
        print_answer();
        exit(0);
    }

    for (int i = 0; i < 3; i++) {
        v.push_back(arr[i]);
        if (is_able()) {
            choose(idx + 1);
        }
        v.pop_back();
    }
    
}

int main() {
    cin >> n;

    choose(0);

    return 0;
}