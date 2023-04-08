#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;

            ans += a;
        }

        int mx = -1;
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;

            mx = max(mx, b);
            ans += b;
        }

        ans -= mx;
        cout << ans << '\n';
    }
}