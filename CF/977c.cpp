#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    int ans;
    if (k == 0) ans = a[1] - 1;
    else ans = a[k];

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= ans) cnt++;
    }

    if (ans < 1 || ans > 1e9 || cnt != k) cout << -1;
    else cout << ans;
}