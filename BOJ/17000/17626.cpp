#include <iostream>
using namespace std;

int dp[50001];

int main() {
    int n;
    cin >> n;
    fill(dp+1, dp+n+1, 5);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    
    cout << dp[n];
}