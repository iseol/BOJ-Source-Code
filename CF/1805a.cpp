#include <iostream>
using namespace std;

int a[1005], b[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        
        bool flag = false;
        for (int x = 0; x < 256; x++) {
            if (flag) break;

            for (int i = 0; i < n; i++) {
                b[i] = x^a[i];
            }

            int res = b[0];
            for (int i = 1; i < n; i++) {
                res ^= b[i];
            }

            if (res == 0) {
                cout << x << '\n';
                flag = true;
                break;
            }
        }
    
        if (!flag) cout << -1 << '\n';
    }
}