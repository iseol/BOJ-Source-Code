#include <iostream>
using namespace std;

typedef long long ll;
int arr[10001];
int k, n;

bool solve(ll x) {
    ll cur = 0;
    for (int i = 0; i < k; i++) cur += arr[i] / x;
    return cur >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> arr[i];

    ll st = 1;
    ll en = (1LL<<31);

    while (abs(en - st) > 1) {
        
        ll mid = (st + en) / 2;
        cout << st << ' ' << mid << ' ' << en << '\n';

        if (solve(mid)) st = mid;
        else en = mid;
    }
    cout << st;
}