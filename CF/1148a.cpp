#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll k = min(a, b);
    ll res;
    if (a-k == 0 && b-k == 0) res = 0;
    else if (a-k == 0 || b-k == 0) res = 1;
    else res = 2;

    cout << 2*c + 2*k + res;
}