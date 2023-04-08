#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, x, y;
        cin >> n >> x >> y;

        if (x > y) swap(x, y);

        if (x || !y || (n-1) % y) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 2; i <= n; i += y) {
            for (int j = 1; j <= y; j++) cout << i << ' ';
        }
        cout << '\n';
    }
}