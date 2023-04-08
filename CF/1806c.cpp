#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll p[400005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        ll ans = 0, sum = 0;
        for (int i = 1; i <= 2*n; i++) {
            cin >> p[i];
            ans += abs(p[i]);
            sum += abs(p[i] - (-1));
        }

        if (n == 1) ans = min(ans, abs(p[1] - p[2]));
        if (n == 2) ans = min(ans, abs(p[1] - 2) + abs(p[2] - 2) + abs(p[3] - 2) + abs(p[4] - 2));
        if (n % 2 == 0) {
            for (int i = 1; i <= 2*n; i++) {
                ans = min(ans, sum - abs(p[i] - (-1)) + abs(p[i] - n));
            }
        }

        cout << ans << '\n';
    }
}