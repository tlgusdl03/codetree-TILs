#include <iostream>
#define MAX_NUM 100
using namespace std;

int N;
char alpha[MAX_NUM + 1] = {'X', };
int maxRight = 0;
int main() {
    fill_n(alpha, MAX_NUM + 1, 'X');

    cin >> N;

    for (int i = 0; i < N; i++) {
        int p;
        char c;

        cin >> p >> c;
        alpha[p] = c;

        maxRight = max(maxRight, p);
    }

    int result = 0;
    for (int i = 0; i <= maxRight; i++){
        for (int j = i + 1; j <= maxRight; j++){
            if (alpha[i] == 'X' || alpha[j] == 'X') continue;

            int cntG = 0;
            int cntH = 0;
            int size = 0;

            for (int k = i; k <= j; k++){
                if (alpha[k] == 'G') cntG++;
                else if (alpha[k] == 'H') cntH++;
            }

            if (cntG == 0 || cntH == 0 || cntG == cntH){
                size = j - i;
                result = max(result, size);
            } 
        }
    }

    cout << result;
    return 0;
}