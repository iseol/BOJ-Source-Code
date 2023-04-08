#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        ll mx = -1e9;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        sort(a.begin(), a.end(), [](ll a, ll b) {return abs(a) > abs(b);});
        if (mx < 0) {
            cout << a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5] << '\n';
            continue;
        }

        ll ans = a[0] * a[1] * a[2] * a[3] * a[4];
        for (int i = 5; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                ll temp = a[i];

                for (int k = 0; k < 5; k++) {
                    if (k != j) temp *= a[k];
                }

                ans = max(ans, temp);
            }
        }
        cout << ans << '\n';
    }
}