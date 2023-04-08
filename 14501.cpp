#include <iostream>
#include <algorithm>
using namespace std;

int dp[17], t[17], p[17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    
    for (int i = n; i >= 1; i--) {
        if (i + t[i] <= n+1) dp[i] = max(dp[i + t[i]] + p[i], dp[i+1]);
        else dp[i] = dp[i+1];
    }

    cout << *max_element(dp, dp+n+1);
}