#include <iostream>
using namespace std;

int a[1001];
string q[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> q[i];

    for (int i = 0; i < m; i++) cin >> a[i];

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int temp[5] = {0, 0, 0, 0, 0}; // a b c d e

        for (int j = 0; j < n; j++) temp[q[j][i]-'A']++;

        int mx = -1;

        for (int j = 0; j < 5; j++) mx = max(mx, temp[j]);
        ans += mx * a[i];
    }

    cout << ans;
}