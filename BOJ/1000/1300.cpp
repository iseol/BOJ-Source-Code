#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, k;

bool solve(ll s) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) cnt += min(n, s/i);

    if (cnt < k) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    ll st = 0;
    ll en = k;

    while (abs(en - st) > 1) {
        ll mid = (st + en) / 2;

        if (solve(mid)) st = mid;
        else en = mid;
    }

    cout << en;
}