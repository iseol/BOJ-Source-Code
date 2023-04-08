#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr long long INF = 121110987654321LL;

vector<int> arr;
long long dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        [&] () {
            for (int j : arr) {
                if (j == val) return;
            }
            arr.push_back(val);
        } ();
    }

    sort(arr.begin(), arr.end());
    n = arr.size();

    for (int i = 1; i <= k; i++) {
        dp[i] = INF;

        for (int j = 0; j < n; j++) {
            if (i >= arr[j]) {
                dp[i] = min(dp[i], dp[i-arr[j]]);
            }
        }
        if (dp[i] != INF) dp[i]++;
    }

    if (dp[k] == INF) cout << -1;
    else cout << dp[k];
}