#include <iostream>
using namespace std;

int a[100005], d[100006];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) d[i] = d[i-1] + a[i];




    int mx = -1e9 - 7;
    for (int i = k; i <= n; i++) mx = max(mx, d[i]-d[i-k]);
    
    cout << mx;
}