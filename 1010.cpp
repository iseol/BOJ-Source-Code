#include <iostream>
using namespace std;

long long dp[31][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i <= 30; i++) dp[i][0] = 1;
    
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
}