#include <iostream>
#include <algorithm>
using namespace std;

int a[105], b[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin  >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (b[i] - a[i] != 0 && b[i] - a[i] != 1) flag = false; 
        }

        cout << ((flag) ? "YES" : "NO") << '\n';
    }
}