#include <iostream>
using namespace std;

int a[606];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int mx = a[0]; 
        int mn = a[0];
        for (int i = 1; i < n; i++) {
            mx |= a[i];
            mn &= a[i];
        }

        cout << mx - mn << '\n';
    }
}