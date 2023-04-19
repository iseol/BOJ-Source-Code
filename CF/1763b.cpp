#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;

typedef long long ll;
pair<ll, ll> a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) cin >> a[i].se; // hp
        for (int i = 0; i < n; i++) cin >> a[i].fi; // power

        sort(a, a+n);
        ll dmg = 0;

        bool flag = true;
        for (int i = 0; i < n; i++) {
            while (dmg < a[i].se) {
                dmg += k;
                k -= a[i].fi;

                if (k <= 0) flag = false;
            }
        }

        cout << ((flag) ? "YES\n" : "NO\n");
    }
}