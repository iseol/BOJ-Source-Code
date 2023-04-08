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
        
        if (r < l*2) cout << "-1 -1\n";
        else cout << l << ' ' << l*2 << '\n';
    }
}