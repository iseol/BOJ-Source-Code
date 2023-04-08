#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int tc;
    cin >> tc;
    while (tc--) {
        long long n;
        cin >> n;

        long long mn = 1e18 + 1, mx = -1;
        if (n == 2 || n % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }

        long long ans = n/4;
        mn = min(ans, mn);
        mx = max(ans, mx);

        if (n != 4 && n % 6 == 0) ans = n/6;
        else ans = n/6 + 1;
        mn = min(ans, mn);
        mx = max(ans, mx);
        
        cout << mn << ' ' << mx << '\n';
    }
}