#include <iostream>
using namespace std;

int d[101][100001], w[101], v[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    int mx = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] <= j) d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
            else d[i][j] = d[i-1][j]; 
            mx = max(mx, d[i][j]);
        }
    }
    cout << mx;
}