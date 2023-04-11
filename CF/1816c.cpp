#include <iostream>
using namespace std;

typedef long long ll;

ll a[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 1; i < n-1; i++) {
            if (a[i-1] > a[i]) {
                ll d = a[i-1] - a[i];
                a[i] += d; a[i+1] += d;
            }
        }

        for (int i = n-2; i >= 1; i--) {
            if (a[i] > a[i+1]) {
                ll d = a[i] - a[i+1];
                a[i] -= d; a[i-1] -= d;
            }
        }

        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (a[i-1] > a[i]) flag = false;
        }

        cout << ((flag) ? "YES\n" : "NO\n");
    }
}