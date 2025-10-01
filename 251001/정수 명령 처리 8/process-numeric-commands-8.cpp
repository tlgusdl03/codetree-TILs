#include <iostream>
#include <list>
#include <string>

using namespace std;

int N;
string command[10000];
int A[10000];
list<int> linkedList;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> A[i];
        }
    }

    for (int i = 0; i < N; i++) {
        string operation = command[i];

        if (operation == "push_front") {
            linkedList.push_front(A[i]);
        } else if (operation == "push_back") {
            linkedList.push_back(A[i]);
        } else if (operation == "pop_front") {
            if (linkedList.empty()) {
                cout << -1 << '\n';
            } else {
                cout << linkedList.front() << '\n';
                linkedList.pop_front();
            }
        } else if (operation == "pop_back") {
            if (linkedList.empty()) {
                cout << -1 << '\n';
            } else {
                cout << linkedList.back() << '\n';
                linkedList.pop_back();
            }
        } else if (operation == "size") {
            cout << linkedList.size() << '\n';
        } else if (operation == "empty") {
            cout << (linkedList.empty() ? 1 : 0) << '\n';
        } else if (operation == "front") {
            if (linkedList.empty()) {
                cout << -1 << '\n';
            } else {
                cout << linkedList.front() << '\n';
            }
        } else if (operation == "back") {
            if (linkedList.empty()) {
                cout << -1 << '\n';
            } else {
                cout << linkedList.back() << '\n';
            }
        }
    }

    return 0;
}
