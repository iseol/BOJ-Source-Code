#include <iostream>
#include <algorithm>
using namespace std;

int a[200005], b[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        
        b[0] = 1;
        for (int i = 1; i < n; i++) b[i] = min(a[i], b[i-1]+1);

        long long ans = 0;
        for (int i = 0; i < n; i++) ans += (a[i] - b[i]);
        
        cout << ans << '\n';
    }
}