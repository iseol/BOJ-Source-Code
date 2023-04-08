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
        [&] () {
            for (long long k = a*b; k <= c*d; k+=a*b) {
                for (int x = a+1; x <= c; x++) {
                    if (k % x == 0) {
                        int y = k / x;
                        if (b < y && y <= d) {
                            cout << x << ' ' << y << '\n';
                            return;
                        }
                    }
                }
            }
            cout << "-1 -1\n";
        } ();

    }
}