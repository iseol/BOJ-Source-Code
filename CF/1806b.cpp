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

        int zero = 0;
        int one = 0;
        int larger = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 0) zero++;
            else if (a == 1) one++;
            else larger++;
        }

        if (n % 2 == 0) {
            if (zero >= n/2 + 1) {
                if (one >= 1) {
                    if (larger >= 1) cout << 1 << '\n';
                    else cout << 2 << '\n';
                }
                else cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
        else {
            if (zero >= n/2 + 2) {
                if (one >= 1) {
                    if (larger >= 1) cout << 1 << '\n';
                    else cout << 2 << '\n';
                }
                else cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
    }
}