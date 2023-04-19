#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> cnt(n+1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        int ans = 0, sum = 0;
        for (int k = 0; k <= n; k++) {
            if (cnt[k] == 0 && sum == k) ans++;
            sum += cnt[k];
        }

        cout << ans << '\n';
    }
}