#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        ll x;
        cin >> x;

        if (x == 0 || x == 1) {
            cout << 2 << '\n';
            continue;
        }

        for (ll i = x;; i++) {
            bool isprime = true;
            for (ll j = 2; j*j <= i; j++) {
                if (i % j == 0) {
                    isprime = false;
                    break;
                }
            }
            if (isprime) {
                cout << i << '\n';
                break;
            }
        }
    }
}