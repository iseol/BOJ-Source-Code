#include <iostream>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        if (x == m) x = 0;
        if (y == n) y = 0;
        
        int l = lcm(m, n);
        [&] () {
            for (int i = x; i <= l; i += m) {
                if (i == 0) continue;
                if (i % n == y) {
                    cout << i << '\n';
                    return;
                }
            }

            cout << -1 << '\n';
        } ();
    }
}