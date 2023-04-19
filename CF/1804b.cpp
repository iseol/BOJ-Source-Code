#include <iostream>
using namespace std;

int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int i = 0, ans = 0;
        while (i < n) {
            int bound = a[i] + d + w;
            ans++;

            int cnt = 0;
            while (cnt < k && a[i] <= bound && i < n) i++, cnt++;
        }

        cout << ans << '\n';
    }
}