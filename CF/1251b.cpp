#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int odd = 0;
        int even = 0;
        int bad = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].length() % 2 != 0) {
                odd++;
                continue;
            }
            
            int zeros = 0;
            int ones = 0;
            for (char c : a[i]) {
                if (c == '0') zeros++;
                else ones++;
            }

            if (zeros % 2 == 0 && ones % 2 == 0) even++;
            else bad++;
        }

        if (odd == 0 && bad % 2 != 0) cout << n-1 << '\n';
        else cout << n << '\n';
    }
}