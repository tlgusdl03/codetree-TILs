#include <iostream>

using namespace std;

int N, K;
int location[10001] = {0, };

int main() {
    cin >> N >> K;

    int x;
    char c;

    for (int i = 0; i < N; i++) {
        cin >> x >> c;
        if (c == 'G'){
            location[x] = 1;
        }
        else if (c == 'H'){
            location[x] = 2;
        }
        
    }

    int result = 0;
    for (int i = 1; i <= 10000 - K; i++){
        int temp = 0;
        for (int j = i; j <= i + K; j++){
            temp += location[j];
            
        }
        result = max(result, temp);
    }

    cout << result;

    return 0;
}