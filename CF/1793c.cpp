#include <iostream>
using namespace std;

int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int l = 1;
        int r = n;

        int mx = n;
        int mn = 1;
        for (int i = 1; i <= n; i++) cin >> a[i];

        while (l <= r) {
            if (a[l] == mx) {
                l++;
                mx--;
            }
            else if (a[l] == mn) {
                l++;
                mn++;
            }
            else if (a[r] == mx) {
                r--;
                mx--;
            }
            else if (a[r] == mn) {
                r--;
                mn++;
            }
            else break;
        }

        if (l <= r) cout << l << ' ' << r << '\n';
        else cout << -1 << '\n';
    }
}