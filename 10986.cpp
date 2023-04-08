#include <iostream>
using namespace std;

long long cnt[1001], d[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i-1];
        d[i] %= m;
        cnt[d[i]]++;
    }

    long long ans = cnt[0];
    for (int i = 0; i < m; i++) {
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    
    cout << ans;
}