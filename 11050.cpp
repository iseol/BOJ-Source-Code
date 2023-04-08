#include <iostream>
using namespace std;

int dp[11][11];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= 10; i++) dp[i][0] = 1;

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    cout << dp[n][k];
}