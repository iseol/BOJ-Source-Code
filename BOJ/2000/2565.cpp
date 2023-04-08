#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> t[501];
int c[101], d[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> t[i].first >> t[i].second;
    sort(t+1, t+n+1);
    for (int i = 1; i <= n; i++) c[i] = t[i].second;

    fill(d+1, d+n+1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= 1; j--) {
            if (c[i] > c[j]) d[i] = max(d[i], d[j]+1);
        }
    }

    int mx = -1;
    for (int i = 1; i <= n; i++) mx = max(mx, d[i]);
    
    cout << n - mx;
}
