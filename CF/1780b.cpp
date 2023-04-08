#include <iostream>
#include <numeric>
using namespace std;

typedef long long ll;

ll a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        ll s = accumulate(a, a+n, 0LL);

        ll ans = 1;
        ll cur = 0;
        for (int i = 0; i < n-1; i++) {
            cur += a[i]; s -= a[i];
            ans = max(ans, gcd(cur, s));
        }

        cout << ans << '\n';
    }
}