#include <iostream>
using namespace std;
typedef long long ll;
const int p = 1000000007;

ll sol(ll a, ll b) {
    if (b == 1) return a % p;

    ll val = sol(a, b/2);
    val = (val * val) % p;
    if (b % 2 == 0) return val;
    return (a * val) % p;
}

int main() {
    int n, k;
    cin >> n >> k;

    ll a = 1;
    for (int i = 1; i <= n; i++) {
        a *= i;
        a %= p;
    }

    ll b = 1;
    for (int i = 1; i <= n-k; i++) {
        b *= i;
        b %= p;
    }
    for (int i = 1; i <= k; i++) {
        b *= i;
        b %= p;
    }

    ll b2 = sol(b, p-2);
    cout << (a * b2) % p;
}
