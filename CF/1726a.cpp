#include <iostream>
using namespace std;

int a[2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];

        int ans = a[n] - a[1];

        a[0] = a[n];
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i-1]-a[i]);
        }

        for (int i = 2; i <= n; i++) {
            ans = max(ans, a[i]-a[1]);
        }

        for (int i = 1; i <= n-1; i++) {
            ans = max(ans, a[n]-a[i]);
        }

        cout << ans << '\n';
    }
}