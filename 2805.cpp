#include <iostream>
using namespace std;
typedef long long ll;

int n, m;
int arr[1000001];

bool solve(ll x) {
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - x > 0) cur += arr[i] - x;
    }
    return cur >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll st = 0;
    ll en = 1000000000;

    while (st < en) {
        ll mid = (st+en+1) / 2;
        if (solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}