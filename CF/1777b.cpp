#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;

        ll ans = 1;
        for (ll i = 1; i <= n; i++) {
            ans *= i;
            ans %= mod;
        }

        ans *= n; ans %= mod;
        ans *= n-1; ans %= mod;
        cout << ans << '\n';
        
    }
}