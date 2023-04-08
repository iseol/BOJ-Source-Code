#include <iostream>
using namespace std;

int dp[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s = '0' + s;
    if (s[1] == '0') {
        cout << 0;
        return 0;
    }

    int n = s.length() - 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int prev = 10*(s[i-1]-'0') + s[i]-'0';
        if (prev >= 10 && prev <= 26) {
            dp[i] += dp[i-2];
            dp[i] %= 1000000;
        }
        if (s[i] != '0') {
            dp[i] += dp[i-1];
            dp[i] %= 1000000;
        }
    }

    cout << dp[n];
}