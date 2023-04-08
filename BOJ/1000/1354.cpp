#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll dp[10000001];
ll n;
int p, q, x, y;


ll solve(ll i) {
    if (i <= 0) return 1;
    if (i <= 10000000) return dp[i];
    return solve(i/p-x) + solve(i/q-y);
}

int main() {
    cin >> n >> p >> q >> x >> y;

    dp[0] = 1;

    for (int i = 1; i <= 10000000; i++) {
        dp[i] = dp[max(i/p-x, 0)] + dp[max(i/q-y, 0)];
    }
    
    cout << solve(n);
}