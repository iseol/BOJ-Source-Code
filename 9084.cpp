#include <iostream>
using namespace std;

int c[21], dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> c[i];

        int m;
        cin >> m;

        dp[0] = 1;
        /*for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= c[j]) dp[i] += dp[i-c[j]];
            }
        }*/
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j >= c[i]) dp[j] += dp[j-c[i]];
            }
        }
        cout << dp[m] << '\n';
        fill(dp, dp+m+1, 0);
    }
}