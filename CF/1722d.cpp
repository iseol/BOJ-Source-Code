#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') ans += i;
            else ans += n-i-1;
        }

        int k = 0;
        for (int i = 0; i < n/2; i++) { //
            if (s[i] == 'L') {
                ++k;
                ans += n-i-i-1;
                cout << ans << ' ';
            }

            int j = n-i-1;
            if (s[j] == 'R') {
                ++k;
                ans += -n+j+j+1;
                cout << ans << ' ';
            }
        }
        
        if (k <= n) {
            for (; k != n; k++) cout << ans << ' ';
        }
        cout << '\n';
    }
}