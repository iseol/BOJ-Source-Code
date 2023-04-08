#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    /*if (m == 0) {
        cout << 1;
        return 0;
    }*/
    
    ll a1 = 0;
    ll a2 = 0;
    for (ll i = 2; i <= n; i*=2) a1 += n / i;
    for (ll i = 5; i <= n; i*=5) a2 += n / i;

    ll b1 = 0;
    ll b2 = 0;
    for (ll i = 2; i <= m; i*=2) b1 += m / i;
    for (ll i = 5; i <= m; i*=5) b2 += m / i;

    ll c1 = 0;
    ll c2 = 0;
    for (ll i = 2; i <= n-m; i*=2) c1 += (n-m) / i;
    for (ll i = 5; i <= n-m; i*=5) c2 += (n-m) / i;
    
    cout << min(a1-b1-c1, a2-b2-c2);
}