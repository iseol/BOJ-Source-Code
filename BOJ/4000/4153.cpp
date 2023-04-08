#include <iostream>
#include <algorithm>
using namespace std;

int l[3];

int main() {
    while (1) {
        cin >> l[0] >> l[1] >> l[2];
        if (l[0] == 0) return 0;
        sort(l, l+3);
        if (l[2]*l[2] == l[1]*l[1]+l[0]*l[0]) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
}