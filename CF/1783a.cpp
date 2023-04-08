#include <iostream>
#include <algorithm>
using namespace std;

int a[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];

        if (a[0] == a[n-1]) cout << "NO\n";
        else {
            cout << "YES\n";

            cout << a[n-1] << ' ' << a[0] << ' ';
            for (int i = 1; i < n-1; i++) cout << a[i] << " \n"[i == n-2];
        }
    }
}