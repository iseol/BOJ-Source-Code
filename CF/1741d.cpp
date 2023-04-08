#include <iostream>
#include <cmath>
#define debug for (int i = 1; i <= m; i++) cout << p[i] << ' ';
using namespace std;

int p[262145];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        cin >> m;
        if (m == 1) {
            int temp;
            cin >> temp;
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i <= m; i++) cin >> p[i];

        int ans = 0;
        [&] () {
            for (int i = 1; i <= m; i+=2) {
                if (abs(p[i] - p[i+1]) != 1) {
                    cout << -1 << '\n';
                    return;
                }
                else {
                    if (p[i] > p[i+1]) {
                        swap(p[i], p[i+1]);
                        // debug;
                        ans++;
                    }
                }
            }

            // int h = (int)(log2(m)+0.5);
            for (int i = 2; i <= m/2; i*=2) {
                for (int j = 1; j <= m; j+=(2*i)) {
                    if (abs(p[j] - p[j+i]) != i) {
                        cout << -1 << '\n';
                        return;
                    }
                    else if (p[j] > p[j+i]) {
                        for (int k = j; k < j+i; k++) swap(p[k], p[k+i]);
                        // debug;
                        ans++;
                    }
                }
            }

            cout << ans << '\n';
        } ();
    }
}