#include <iostream>

using namespace std;

int n, m;
int a[100], b[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    int result = 0;
    for (int i = 1; i <= n; i++) { 
        for (int j = i + 1; j <= n; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                if ((a[k] == i || a[k] == j) && (b[k] == i || b[k] == j)) cnt++;
            }
            result = max(result, cnt);
        }
    }

    cout << result;
    
    return 0;
}