#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int l, r;
        cin >> l >> r;
        cout << l << ' ' << 2*l << '\n';
    }
}