#include <iostream>
#include <list>
#include <string>

using namespace std;

int n, m;
char command[100000];
char c[100000];
list<char> s;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        char bread;
        cin >> bread;
        s.push_back(bread);
    }

    for (int i = 0; i < m; i++) {
        cin >> command[i];
        if (command[i] == 'P') {
            cin >> c[i];
        }
    }

    list<char>::iterator it;
    it = s.end();

    for (int i = 0; i < m; i++) {

        if (command[i] == 'L') {
            if (it != s.begin()) {
                it--;
            }
        }
        else if (command[i] == 'R') {
            if (it != s.end()) {
                it++;
            }

        }
        else if (command[i] == 'D') {
            if (it != s.end()) {
                it = s.erase(it);
            }

        }
        else if (command[i] == 'P') {
            s.insert(it, c[i]);
        }
    }

    for (it = s.begin(); it != s.end(); it++) {
        cout << *it;
    }

    return 0;
}

//codest
