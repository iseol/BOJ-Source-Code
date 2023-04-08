#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int op = -1;
    for (int i = 0; i < n-1; i++) {
        if (s[i] > s[i+1]) {
            op = i;
            break;
        }
    }

    if (op == -1) {
        for (int i = 0; i < n-1; i++) cout << s[i];
    }
    else {
        for (int i = 0; i < n; i++) {
            if (op == i) continue;
            cout << s[i];
        }
    }
}