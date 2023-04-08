#include <iostream>
using namespace std;

long long a[200005], s[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i-1] + a[i];
        }

        for (int i = 1; i <= q; i++) {
            int l, r, k;
            cin >> l >> r >> k;

            if ((s[n] - s[r] + (k*(r-l+1)) + s[l-1]) % 2 != 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}