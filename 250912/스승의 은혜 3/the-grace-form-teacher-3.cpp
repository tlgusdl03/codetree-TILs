#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int p, s;
};

bool compare(Node &a, Node &b) {
    return (a.p + a.s) < (b.p + b.s);
}

int N, B;
vector<Node> arr;

int main() {
    cin >> N >> B;

    int p, s;
    for (int i = 0; i < N; i++) {
        cin >> p >> s;
        arr.push_back({p, s});
    }

    sort(arr.begin(), arr.end(), compare);

    int result = 0;

    for (int i = 0; i < N; i++) {
        int count = 0;
        int sum = 0;
        for (int j = 0; j < N; j++) {
            int nextPrice = 0;
            if (i == j) {
                nextPrice += arr[j].p / 2 + arr[j].s;
            }
            else {
                nextPrice += arr[j].p + arr[j].s;
            }

            sum += nextPrice;

            if (sum <= B) {
                count++;
            }
            else {
                break;
            }
        }
        result = max(result, count);
    }

    cout << result;

    return 0;
}