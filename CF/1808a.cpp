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

        int ans = -1;
        int rans;
        for (int i = l; i <= r; i++) {
            int tmp = i;

            int mx = -1, mn = 10;
            while (tmp > 0) {
                int d = tmp % 10;
                tmp /= 10;

                mx = max(mx, d);
                mn = min(mn, d);
            }

            int res = abs(mx-mn);

            if (ans < res) {
                ans = res;
                rans = i;
            }
            if (ans == 9) break;
        }
        
        cout << rans << '\n';
    }
}