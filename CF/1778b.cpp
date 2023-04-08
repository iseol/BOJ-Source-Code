#include <iostream>
using namespace std;

int p[500005];
int a[500005];
int pos[500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, d;
        cin >> n >> m >> d;

        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= m; i++) cin >> a[i];

        for (int i = 1; i <= n; i++) pos[p[i]] = i;

        int ans = 1e9;
        for (int i = 1; i <= m-1; i++) {
            if (pos[a[i+1]] <= pos[a[i]]) {
                ans = 0;
            }
            else {
                ans = min(ans, pos[a[i+1]]-pos[a[i]]);
            }

            if (pos[a[i+1]]-pos[a[i]] > d) {
                ans = 0;
            }
            else if (n-1 > d) {
                ans = min(ans, d-(pos[a[i+1]]-pos[a[i]])+1);
            }
        }

        cout << ans << '\n';
    }
}