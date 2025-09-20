#include <iostream>

using namespace std;

int n;
int adjacent[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> adjacent[i];
    }

    for (int i = 1; i <= n; i++) {

        bool pass = true;
        bool appeared[1000] = {false, };
        int answer[1000] = {};
        
        answer[0] = i;
        appeared[i] = true;
 
        for (int j = 1; j < n; j++) {

            int num = adjacent[j - 1] - answer[j - 1];

            if (num < 1 || num > n || appeared[num]) {
                pass = false;
                break;
            }

            answer[j] = num;
            appeared[num] = true;
        }

        if (pass) {
            for (int j = 0; j < n; j++) {
                cout << answer[j] << " ";
            }
            return 0;
        }
    }

    return 0;
}