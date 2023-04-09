#include <iostream>
using namespace std;

int a[35];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        [] () {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) cin >> a[i];

            int ans = 0;
            for (int i = n-2; i >= 0; i--) {
                while (a[i] > 0 && a[i+1] <= a[i]) {
                    a[i] /= 2;
                    ans++;
                }

                if (a[i+1] == a[i]) {
                    cout << "-1\n";
                    return;
                }
            }

            cout << ans << '\n';
        } ();
    }
}