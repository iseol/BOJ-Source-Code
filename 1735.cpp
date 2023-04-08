#include <iostream>
#include <numeric>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    ll c, d;

    cin >> a >> b;
    cin >> c >> d;

    a *= lcm(b, d) / b;
    c *= lcm(b, d) / d;

    ll x = a + c;
    cout << x / gcd(lcm(b, d), x) << ' ' << lcm(b, d) / gcd(lcm(b, d), x);
 }