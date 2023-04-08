#include <iostream>
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
        
        int p = 0;
        int m = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > 0) p++;
            else m++;
        }

        for (int i = 1; i <= p; i++) cout << i << ' ';
        for (int i = 1; i <= m; i++) cout << p - i << ' ';
        cout << '\n';
        
        for (int i = 1; i <= m; i++) cout << 1 << ' ' << 0 << ' ';
        for (int i = 1; i <= n-2*m; i++) cout << i << ' ';
        cout << '\n';
    }
}