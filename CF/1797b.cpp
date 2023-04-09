#include <iostream>
using namespace std;

int a[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != a[n-i-1][n-j-1]) cnt++;
            }
        }

        cnt /= 2;

        if (cnt > k) cout << "NO\n";
        else if ((k - cnt) % 2 != 0) {
            if (n % 2 != 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "YES\n";
    }
}