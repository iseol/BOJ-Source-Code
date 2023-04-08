#include <iostream>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        
        int mn = 1e6, mx = -1;
        for (int i = 0; i < n; i++) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        long long mnc = 0, mxc = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mn) mnc++;
            if (a[i] == mx) mxc++;
        }

        if (mn == mx) cout << mxc * (mxc - 1) << '\n';
        else cout << mxc * mnc * 2 << '\n';

    }
}