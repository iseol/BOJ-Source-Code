#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    int ans = 0;
    int mn = 0;

        for (int i = m; i <= n; i++) {
            if (i == 1) continue;
            [&] () {
                for (int j = 2; j*j <= i; j++) {
                    if (i % j == 0) return;
                }
                ans += i;
                if (ans == i) mn = i;
            } ();

        }



    if (ans == 0) cout << -1;
    else cout << ans << '\n' << mn;
}