#include <iostream>
#include <vector>
#include <map>
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
        
        map<ll, ll> cnt;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= n; i++) cnt[a[i]-i]++;

        ll ans = 0;

        map<ll, ll>::iterator i;
        for (i = cnt.begin(); i != cnt.end(); i++) {
            ans += i->second * (i->second - 1) / 2;
        }
        cout << ans << '\n';
    }
}