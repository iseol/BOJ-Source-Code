#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;

        if (min(sx - 1, m - sy) <= d && min(n - sx, sy - 1) <= d) cout << "-1\n";
        else cout << n+m-2 << '\n';
    }
}