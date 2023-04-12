#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        long long x, n;
        cin >> x >> n;

        if (x % 2 == 0) {
            if (n % 4 == 0) cout << x << '\n';
            else if (n % 4 == 1) cout << x - n << '\n';
            else if (n % 4 == 2) cout << x + 1 << '\n';
            else cout << x + n + 1 << '\n';
        }
        else {
            if (n % 4 == 0) cout << x << '\n';
            else if (n % 4 == 1) cout << x + n << '\n';
            else if (n % 4 == 2) cout << x - 1 << '\n';
            else cout << x - n - 1 << '\n';
        }
    }
}