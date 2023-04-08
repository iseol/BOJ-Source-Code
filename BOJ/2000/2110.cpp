#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, c;
int house[200005];

bool solve(int dist) {
    int cnt = 1;
    int prev = house[0];

    for (int i = 0; i < n; i++) {
        if (house[i] - prev >= dist) {
            cnt++;
            prev = house[i];
        }
    }


    if (cnt >= c) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> house[i];

    sort(house, house+n);

    ll st = 1;
    ll en = house[n-1] - house[0] + 1;

    while (abs(en - st) > 1) {
        ll mid = (st + en) / 2;

        // cout << st << ' ' << mid << ' ' << en << '\n';

        if (solve(mid)) st = mid;
        else en = mid;
    }
    
    cout << st;
}