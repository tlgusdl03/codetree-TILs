#include <iostream>

using namespace std;

int n;
char c[100];
int s[100];
int one = 0;
int count = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    int A = 0, B = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] == 'A') {
            A += s[i];
        }
        else if (c[i] == 'B') {
            B += s[i];
        }

        if (A > B) {
            if (one != 1) {
                one = 1;
                count++;
            }
        }
        else if (A < B) {
            if (one != 2) {
                one = 2;
                count++;
            }
        }
        else if (A == B) {
            if (one != 0) {
                one = 0;
                count++;
            }
        } 
    }

    cout << count;
    return 0;
}