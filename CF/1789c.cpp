#include <iostream>
using namespace std;

long long a[200005], cnt[400005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]] = m+1;
        }

        for (int i = 0; i < m; i++) {
            int p, v;
            cin >> p >> v;
            p--;

            cnt[a[p]] -= m-i;
            a[p] = v;
            cnt[a[p]] += m-i;
        }

        long long ans = 0;
        for (int i = 1; i <= n+m; i++) {
            ans += cnt[i] * (cnt[i] - 1) / 2;
            ans += cnt[i] * (m+1 - cnt[i]);
        }

        cout << ans << '\n';
        fill(cnt, cnt+n+m+1, 0);
    }
}