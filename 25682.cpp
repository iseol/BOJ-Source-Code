#include <iostream>
using namespace std;

char board[2001][2001];
long long dp[2][2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            board[i][j] = s[j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 != 0) {
                if (j % 2 != 0) {
                    if (board[i][j] != 'B') dp[0][i][j]++;
                }
                else {
                    if (board[i][j] != 'W') dp[0][i][j]++;
                }
            }
            else {
                if (j % 2 != 0) {
                    if (board[i][j] != 'W') dp[0][i][j]++;
                }
                else {
                    if (board[i][j] != 'B') dp[0][i][j]++;
                }
            }
            dp[0][i][j] += dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 != 0) {
                if (j % 2 != 0) {
                    if (board[i][j] != 'W') dp[1][i][j]++;
                }
                else {
                    if (board[i][j] != 'B') dp[1][i][j]++;
                }
            }
            else {
                if (j % 2 != 0) {
                    if (board[i][j] != 'B') dp[1][i][j]++;
                }
                else {
                    if (board[i][j] != 'W') dp[1][i][j]++;
                }
            }
            dp[1][i][j] += dp[1][i-1][j] + dp[1][i][j-1] - dp[1][i-1][j-1];
        }
    }

    long long ans = 1LL<<61;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ans = min(
                    ans,
                    min(dp[0][i][j] - dp[0][i-k][j] - dp[0][i][j-k] + dp[0][i-k][j-k],
                    dp[1][i][j] - dp[1][i-k][j] - dp[1][i][j-k] + dp[1][i-k][j-k])
                );
        }
    }

    cout << ans;

}