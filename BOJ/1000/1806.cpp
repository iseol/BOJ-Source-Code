#include <iostream>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> a[i];

    long long tot = a[0];
    int ans = 0x7fffffff;
    int en = 0;
    
    for (int st = 0; st < n; st++) {
        while (en < n && tot < s) {
            en++;
            if (en != n) tot += a[en];
        }
        if (en == n) break;

        ans = min(ans, en - st + 1);
        tot -= a[st];
    }

    if (ans == 0x7fffffff) ans = 0;
    cout << ans;
}