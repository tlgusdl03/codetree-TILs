#include <iostream>

using namespace std;

int N;

void printRec(int N) {
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << num << " ";
            num++;
            if (num == 10) {
                num = 1;
            }
        }
        cout << '\n';
    }
}
int main() {
    cin >> N;

   printRec(N); 

    return 0;
}