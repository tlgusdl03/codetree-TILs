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
        vector<int> prices;
        for (int j = 0; j < N; j++) {
            if (j == i)
                prices.push_back(arr[j].p / 2 + arr[j].s);
            else
                prices.push_back(arr[j].p + arr[j].s);
        }
        sort(prices.begin(), prices.end());
        int sum = 0, count = 0;
        for (int price : prices) {
            sum += price;
            if (sum <= B) count++;
            else break;
        }
        result = max(result, count);
    }

    cout << result;

    return 0;
}