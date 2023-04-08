#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int ans = 0;
        if (d - b < 0) {
            cout << -1 << '\n';
            continue;
        }
        else {
            ans += d - b;
            a += d - b;
            if (c - a <= 0) ans += a - c;
            else {
              cout << -1 << '\n';
            continue;  
            }
        }
        cout << ans << '\n';
    }
}