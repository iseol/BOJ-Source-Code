#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) cin >> a[i];
        [&] () {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;

                    if (gcd(a[i], a[j]) <= 2) {
                        i = j = n;
                        cout << "Yes" << '\n';
                        return;
                    }
                }
            }
            cout << "No" << '\n';
        } ();
    }
}